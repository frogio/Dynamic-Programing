#include <stdio.h>

#pragma warning(disable:4996)

int Fibonacci(int n);

void main() {

	int n;
	printf("n��° �Ǻ���ġ ? ");
	scanf("%d", &n);
	printf("%d", Fibonacci(n));
}

int Fibonacci(int n) {

	if (n < 2)
		return n;
	
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}