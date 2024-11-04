#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char board[50][50];
    char chess1[8][8], chess2[8][8];
    int N, M, min = 2000;
    scanf("%d %d", &N, &M);
    getchar();


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &board[i][j]);
        }
        getchar();
    }

    // W로 시작하는 체스판 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) chess1[i][j] = 'W';
            else chess1[i][j] = 'B';
        }
    }

    // B로 시작하는 체스판 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) chess2[i][j] = 'B';
            else chess2[i][j] = 'W';
        }
    }

    for (int x = 0; x <= N - 8; x++) {
        for (int y = 0; y <= M - 8; y++) {
            int chess1_count = 0, chess2_count = 0;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (board[x + i][y + j] != chess1[i][j]) chess1_count++;
                    if (board[x + i][y + j] != chess2[i][j]) chess2_count++;
                }
            }
            int temp = chess1_count < chess2_count ? chess1_count : chess2_count;
            if (min > temp) min = temp;
        }
    }

    printf("%d", min);
    return 0;
}
