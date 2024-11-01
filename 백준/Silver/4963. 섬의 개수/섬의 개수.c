#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int graph[51][51] = { 0 };
int visited[51][51] = { 0 };
int w, h, land_count = 0;

void DFS(int y, int x) {
	if (x < 1 || y < 1 || x > w || y > h) return;
	if (visited[y][x] || !graph[y][x]) return;
	visited[y][x] = 1;

	DFS(y + 1, x);
	DFS(y + 1, x + 1);
	DFS(y, x + 1);
	DFS(y - 1, x + 1);
	DFS(y - 1, x);
	DFS(y - 1, x - 1);
	DFS(y, x - 1);
	DFS(y + 1, x - 1);
}

int main() {
	while (1){

		scanf("%d %d", &w, &h);
		if (!w && !h) return;

		for (int i = 1; i < h+1; i++) {
			for (int j = 1; j < w+1; j++) {
				scanf("%d", &graph[i][j]);
			}
		}

		for (int i = 1; i < h + 1; i++) {
			for (int j = 1; j < w + 1; j++) {
				if (!visited[i][j] && graph[i][j]) {
					DFS(i, j);
					land_count++;
				}
			}
		}

		printf("%d\n", land_count);

		for (int i = 1; i < h + 1; i++) {
			for (int j = 1; j < w + 1; j++) {
				visited[i][j] = 0;
				graph[i][j] = 0;
			}
		}
		land_count = 0;
	} 
}