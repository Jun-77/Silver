#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Create a 2D array to mark possible treasure locations
    int possible[N+1][N+1];

    // Initialize all positions as possible
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            possible[i][j] = 1;
        }
    }

    // Read each compass usage record
    for (int i = 0; i < M; i++) {
        int X, Y, K;
        scanf("%d %d %d", &X, &Y, &K);

        // For each direction, mark impossible positions
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                if (K == 1 && !(x < X && y == Y)) possible[x][y] = 0;
                if (K == 2 && !(x < X && y > Y)) possible[x][y] = 0;
                if (K == 3 && !(x == X && y > Y)) possible[x][y] = 0;
                if (K == 4 && !(x > X && y > Y)) possible[x][y] = 0;
                if (K == 5 && !(x > X && y == Y)) possible[x][y] = 0;
                if (K == 6 && !(x > X && y < Y)) possible[x][y] = 0;
                if (K == 7 && !(x == X && y < Y)) possible[x][y] = 0;
                if (K == 8 && !(x < X && y < Y)) possible[x][y] = 0;
            }
        }
    }

    // Find the remaining possible treasure location
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (possible[i][j]) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    return 0;
}