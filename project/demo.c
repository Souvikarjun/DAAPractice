#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <conio.h> // For _kbhit() and _getch()

#define GRID_SIZE 20
#define CELL_SIZE 3
#define MAX_GHOSTS 1

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position position;
} PacMan;

typedef struct {
    Position position;
} Ghost;

// Function prototypes
void draw_grid(PacMan *pacman, Ghost *ghost);
void move_pacman(PacMan *pacman, char direction);
void move_ghost(Ghost *ghost, Position target);
void dijkstra(Position start, Position target, Position *path, int *path_length);

int main() {
    PacMan pacman = {{1, 1}};
    Ghost ghost = {{5, 5}};
    char input;

    while (true) {
        system("cls"); // Clear the console
        draw_grid(&pacman, &ghost);

        if (_kbhit()) {
            input = _getch();
            switch (input) {
                case 'w': move_pacman(&pacman, 'u'); break; // Up
                case 's': move_pacman(&pacman, 'd'); break; // Down
                case 'a': move_pacman(&pacman, 'l'); break; // Left
                case 'd': move_pacman(&pacman, 'r'); break; // Right
                case 'q': exit(0); // Quit
            }
        }

        move_ghost(&ghost, pacman.position);
        _sleep(100); // Sleep for a short period
    }

    return 0;
}

void draw_grid(PacMan *pacman, Ghost *ghost) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (pacman->position.x == x && pacman->position.y == y) {
                printf(" P ");
            } else if (ghost->position.x == x && ghost->position.y == y) {
                printf(" G ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void move_pacman(PacMan *pacman, char direction) {
    switch (direction) {
        case 'u': if (pacman->position.y > 0) pacman->position.y--; break; // Up
        case 'd': if (pacman->position.y < GRID_SIZE - 1) pacman->position.y++; break; // Down
        case 'l': if (pacman->position.x > 0) pacman->position.x--; break; // Left
        case 'r': if (pacman->position.x < GRID_SIZE - 1) pacman->position.x++; break; // Right
    }
}

void move_ghost(Ghost *ghost, Position target) {
    Position path[GRID_SIZE * GRID_SIZE];
    int path_length = 0;

    dijkstra(ghost->position, target, path, &path_length);
    if (path_length > 1) {
        ghost->position = path[1]; // Move towards the next position in the path
    }
}

void dijkstra(Position start, Position target, Position *path, int *path_length) {
    // Placeholder for Dijkstra's algorithm implementation
    // For demonstration, we will directly set the path to the target
    path[0] = start;
    path[1] = target; // Simplified for demonstration
    *path_length = 2;
}