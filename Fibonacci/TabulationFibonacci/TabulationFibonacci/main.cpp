#include <stdio.h>

#pragma warning(disable:4996)

#define TABLE_MAX	1000

int Fibonacci(int n);

void main() {

	int n;
	printf("n번째 피보나치 ? ");
	scanf("%d", &n);
	printf("%d", Fibonacci(n));

}

int Fibonacci(int n) {

	int table[TABLE_MAX] = {0,};
	table[1] = 1;
	// 기저 상태로부터 시작해서

	for (int i = 2; i <= n; i++)
		table[i] = table[i - 1] + table[i - 2];
	// 문제의 해답까지 기록하면서 올라간다.

	return table[n];
}