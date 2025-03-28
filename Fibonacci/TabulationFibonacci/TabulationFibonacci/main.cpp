#include <stdio.h>

#pragma warning(disable:4996)

#define TABLE_MAX	1000

int Fibonacci(int n);

void main() {

	int n;
	printf("n��° �Ǻ���ġ ? ");
	scanf("%d", &n);
	printf("%d", Fibonacci(n));

}

int Fibonacci(int n) {

	int table[TABLE_MAX] = {0,};
	table[1] = 1;
	// ���� ���·κ��� �����ؼ�

	for (int i = 2; i <= n; i++)
		table[i] = table[i - 1] + table[i - 2];
	// ������ �ش���� ����ϸ鼭 �ö󰣴�.

	return table[n];
}