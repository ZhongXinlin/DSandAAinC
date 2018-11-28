#include<stdio.h>
#define ABS(x) (x>=0 ? x:-(x))
int main()
{
	int N, n,j;
	char c;	
	scanf_s("%d %c", &N, &c);

	for (n = 1; 2 * n*n - 1 <= N; n++);
	n--;

	for (int i = 1; i <= 2*n - 1; i++) {
		for (j = 0; j < n - 1 - ABS(n - i); j++)
			putchar(' ');
		for (j = 0; j < 2 * ABS(n-i)+1; j++)
			putchar(c);
		putchar('\n');
	}
	printf("%d", N-2 * n*n + 1);

	return 0;
}