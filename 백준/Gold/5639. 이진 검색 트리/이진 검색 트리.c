#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 전위순회는 루트노드를 기준으로 왼쪽은 작은 값, 오른쪽은 큰 값임.
// 이를 이용해 왼쪽 서브트리에서 후위순회, 오른쪽 서브트리에서 후위순회
void postorder(int pre[], int start, int end) {
    // start가 end를 초과하면 더 이상 순회할 노드가 없다는 의미이므로 종료
    if (start > end) {
        return;
    }

    int root = pre[start];
    int index = start + 1;

    // 루트보다 큰 값이 나올 때까지 인덱스를 증가
    while (index <= end && pre[index] < root) {
        index++;
    }

    // 왼쪽 서브트리에 대한 후위 순회
    postorder(pre, start + 1, index - 1);
    // 오른쪽 서브트리에 대한 후위 순회
    postorder(pre, index, end);
    // 현재 루트를 출력
    printf("%d\n", root);
}

int main() {
    int pre[10001];
    int count = 0;

    // 입력을 안할 때까지 계속 입력받음
    while (scanf("%d", &pre[count]) != EOF) {
        count++;
    }

    // 후위 순회를 호출하여 결과를 출력
    postorder(pre, 0, count - 1);

    return 0;
}