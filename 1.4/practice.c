#include <stdio.h>
#include <limits.h>

#define n 6
void chainorder(int p[], int cost[n][n], int k[n][n]) {
    for (int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;
            for (int x = i; x < j; x++) {
                int q = cost[i][x] + cost[x + 1][j] + p[i] * p[x + 1] * p[j + 1];
                if (q < cost[i][j]) {
                    cost[i][j] = q;
                    k[i][j] = x;
                }
            }
        }
    }
}

void printmatrices(int cost[n][n], int k[n][n]) {
    printf("Cost matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                printf(" \t");
            } else {
                printf("%d\t", cost[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nK matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                printf(" \t");
            } else {
                printf("%d\t", k[i][j]+1);
            }
        }
        printf("\n");
    }
}

void parenthesis(int k[n][n], int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        parenthesis(k, i, k[i][j]);
        parenthesis(k, k[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int p[n + 1] = {30, 35, 15, 5, 10,20,25};
    int cost[n][n] = {0};
    int k[n][n] = {0};
    chainorder(p, cost, k);
    printmatrices(cost, k);
    printf("Matrix multiplication order: ");
    parenthesis(k, 0, n - 1);
    printf("\n");
    return 0;
}