#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int n;
	int wine[10001] = { 0 };
	int dp[10001];

	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &wine[i]);
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i < n + 1; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + wine[i]);
		dp[i] = max(dp[i], dp[i - 3] + wine[i] + wine[i - 1]);
	}

	printf("%d", dp[n]);
}