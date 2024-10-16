#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int T,H,W,N;
	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++)
	{
		int x,y;
		scanf("%d %d %d", &H, &W, &N);
		x = N % H;
		if (x == 0)
			x = H;
		y= N / H + 1;
		if (N % H == 0)
			y--;
		printf("%d%02d\n", x, y);
	}
	return 0;
}