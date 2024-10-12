#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num_arr[9];
	int max_num = 0, max_num_index = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &num_arr[i]);
		if (num_arr[i] > max_num) {
			max_num = num_arr[i];
			max_num_index = i + 1;
		}
	}
	printf("%d\n%d", max_num, max_num_index);
	return 0;
}