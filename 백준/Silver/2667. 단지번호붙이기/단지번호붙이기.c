#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int graph[26][26] = { 0 };
int apart[26 * 26] = { 0 };
int n, count, sum = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return 0;
    }
    if (graph[x][y] == 1) {
        graph[x][y] = 0; 
        count++; 
        for (int i = 0; i < 4; i++) {
            dfs(x + dx[i], y + dy[i]);
        }
        return 1;
    }
    return 0;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {  
                count = 0;           
                if (dfs(i, j) == 1) {
                    apart[sum++] = count; 
                }
            }
        }
    }

    printf("%d\n", sum);

    for (int i = 0; i < sum - 1; i++) {
        for (int j = i + 1; j < sum; j++) {
            if (apart[i] > apart[j]) {
                int temp = apart[i];
                apart[i] = apart[j];
                apart[j] = temp;
            }
        }
    }

    for (int i = 0; i < sum; i++) {
        printf("%d\n", apart[i]);
    }

    return 0;
}