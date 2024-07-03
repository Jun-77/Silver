#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100001

int main() {
    int top = -1;
    char data[MAX_STACK_SIZE];
    char string[MAX_STACK_SIZE];

    // fgets 사용하여 문자열 입력 받기
    fgets(string, MAX_STACK_SIZE, stdin);

    // 문자열 끝에 개행 문자가 있을 경우 제거
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }

    for (int i = 0; i < strlen(string); i++) {
        // 태그 전까지 스택에 들어있던 문자열 전부 pop(reverse 출력) 및 태그는 그대로 출력
        if (string[i] == '<') {
            while (top != -1) {
                printf("%c", data[top]);
                top--;
            }
            while (string[i] != '>') {
                printf("%c", string[i]);
                i++;
            }
            // 닫는 태그 '>'를 출력하고 다음 문자로 넘어가기
            printf("%c", string[i]);
        }
        // 공백 전까지 스택에 들어있던 문자열 전부 pop(reverse 출력)
        else if (string[i] == ' ') {
            while (top != -1) {
                printf("%c", data[top]);
                top--;
            }
            printf(" "); // 공백 출력
        }
        // 스택에 push
        else {
            data[++top] = string[i];
        }
    }

    // 남아있는 문자열 출력
    while (top != -1) {
        printf("%c", data[top]);
        top--;
    }

    return 0;
}