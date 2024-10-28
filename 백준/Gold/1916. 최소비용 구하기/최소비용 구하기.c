#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 987654321

int N, M, S, E;
int check[1001];
int graph[1001][1001];
int distance[1001];
int start, end, current, weight;

int main() {
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 1; i <= N; i++) {
        distance[i] = INF;
        for (int j = 1; j <= N; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &S, &E, &weight);
        if (graph[S][E] > weight) { 
            graph[S][E] = weight;
        }
    }

    scanf("%d %d", &start, &end);
    distance[start] = 0;

    for (int i = 1; i <= N; i++) {
        int min = INF;
        current = -1;

        for (int j = 1; j <= N; j++) {
            if (!check[j] && min > distance[j]) {
                min = distance[j];
                current = j;
            }
        }

        if (current == -1) break;
        check[current] = 1; 

        for (int next = 1; next <= N; next++) {
            if (graph[current][next] != INF && distance[next] > distance[current] + graph[current][next]) {
                distance[next] = distance[current] + graph[current][next];
            }
        }
    }

    printf("%d\n", distance[end]);
    return 0;
}