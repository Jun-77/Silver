
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, A, B, temp;
	int good_onion = 1, bad_onion = 1;

	scanf("%d %d %d", &N, &A, &B);

	for (int i = 0; i < N; i++) {
		good_onion = good_onion + A;
		bad_onion = bad_onion + B;

		if (good_onion < bad_onion) {
			temp = good_onion;
			good_onion = bad_onion;
			bad_onion = temp;
		}
		else if (good_onion == bad_onion) bad_onion--;
	}

	printf("%d %d", good_onion, bad_onion);
}
