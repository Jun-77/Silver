#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[100000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &dp[i]);
	}

	int max = dp[0];
	for (int i = 1; i < n; i++) {
		int temp = dp[i];
		if (dp[i - 1] + temp > dp[i]) {
			dp[i] = dp[i - 1] + temp;
		}
		if (dp[i] > max) {
			max = dp[i];
		}
	}
	printf("%d", max);
}