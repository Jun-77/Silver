#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int check[5][11] = { 0 };
	char keyboard[5][11];
	char input_key[10];
	for (int i = 0; i < 4; i++) {
		scanf("%s", &keyboard[i]);
		getchar();
	}
	scanf("%s", &input_key);

	for (int i = 0; i < 9; i++) {
		int j = 0;
		// if search correct keyboard, exit keyboard searching roop and i + 1.
		while (j < 4) {
			for (int k = 0; k < 10; k++) {
				if (input_key[i] == keyboard[j][k]) {
					check[j][k] = 1;
					j = 4; // exit nested roop
					break;
				}
			}
			j++;
		}
	}
	

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			if (check[i][j] == 1) {
				char ans = keyboard[i + 1][j + 1];
				printf("%c", ans);
				return 0;
			}
		}
	}
}