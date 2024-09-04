#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, K, count = 0, coin[10];
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &coin[i]);
	}

	if (N == 1) {
		printf("%d", K);
		return 0;
	}

	while (K != 0) {
		for (int i = 0; i < N; i++) {
			if (coin[i] == K) {
				K = K - coin[i];
				count++;
				break;
			}
			else if (coin[i] > K) {
				K = K - coin[i - 1];
				count++;
				break;
			}
			else if (i == N - 1) {
				K = K - coin[i];
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}