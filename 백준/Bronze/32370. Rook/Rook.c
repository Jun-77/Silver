
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int Ax, Ay, Bx, By;

	scanf("%d %d", &Ax, &Ay);
	scanf("%d %d", &Bx, &By);

	if (Ax == 0 && Bx != 0) printf("1");
	else if (Ay == 0 && By != 0) printf("1");
	else if ((Ax == 0 && Bx == 0) && (By > Ay)) printf("1");
	else if ((Ay == 0 && By == 0) && (Bx > Ax)) printf("1");

	else if ((Ax == 0 && Bx == 0) && (By < Ay)) printf("3");
	else if ((Ay == 0 && By == 0) && (Bx < Ax)) printf("3");

	else printf("2");
}