#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char string[1001];
    int num;
    scanf("%s", string);
    scanf("%d", &num);

    printf("%c", string[num - 1]);
    return 0;
}