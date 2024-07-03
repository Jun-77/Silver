#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int count;

	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		int iter;
		char string[21];
		scanf("%d", &iter);
		scanf("%s", string);

		for (int j = 0; j < strlen(string); j++) {
			for (int k = 0; k < iter; k++) {
				printf("%c", string[j]);
			}
		}
		printf("\n");
	}
	return 0;
}