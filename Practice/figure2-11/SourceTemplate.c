#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long int main(long int X,unsigned int N)
{
	N = 1; X = 2;
	if (N == 0) {
		return 1;
	}
	else if (N % 2 == 0) {
		printf("%d", main(X*X, N / 2));
	}
	else{
		printf("%d\n", main(X*X, N / 2)*X);
	}
	system("pause");
	return 0;
}