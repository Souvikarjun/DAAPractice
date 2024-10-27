#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
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
bool is_valid_position(int x, int y);

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
        sleep(1); // Sleep for a short period
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
    int dist[GRID_SIZE][GRID_SIZE];
    Position prev[GRID_SIZE][GRID_SIZE];
    bool visited[GRID_SIZE][GRID_SIZE] = {false};
    int dx[] = {0, 0, -1, 1}; // Directions: right, left, up, down
    int dy[] = {1, -1, 0, 0};

    // Initialize distances
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            dist[i][j] = INT_MAX; // Set all distances to infinity
            prev[i][j] = (Position){-1, -1}; // No previous position
        }
    }
    dist[start.y][start.x] = 0; // Distance to start is 0

    for (int count = 0; count < GRID_SIZE * GRID_SIZE; count++) {
        int min_dist = INT_MAX;
        int min_x = -1, min_y = -1;

        // Find the unvisited node with the smallest distance
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (!visited[i][j] && dist[i][j] < min_dist) {
                    min_dist = dist[i][j];
                    min_x = j;
                    min_y = i;
                }
            }
        }

        if (min_x == -1) break; // No more nodes to visit

        visited[min_y][min_x] = true;

        // Update distances of neighbors
        for (int k = 0; k < 4; k++) {
            int new_x = min_x + dx[k];
            int new_y = min_y + dy[k];

            if (is_valid_position(new_x, new_y) && !visited[new_y][new_x]) {
                int new_dist = dist[min_y][min_x] + 1;
                if (new_dist < dist[new_y][new_x]) {
                    dist[new_y][new_x] = new_dist;
                    prev[new_y][new_x] = (Position){min_x, min_y};
                }
            }
        }
    }

    // Build the shortest path
    int x = target.x, y = target.y;
    int length = 0;
    while (x != start.x || y != start.y) {
        path[length++] = (Position){x, y};
        Position prev_pos = prev[y][x];
        x = prev_pos.x;
        y = prev_pos.y;
    }
    path[length++] = start; // Include the start position
    *path_length = length;
}

bool is_valid_position(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE;
}