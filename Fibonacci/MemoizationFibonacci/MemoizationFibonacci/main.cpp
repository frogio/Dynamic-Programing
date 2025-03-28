#include <stdio.h>
#include <memory.h>

#define CACHE_MAX	1000
#define UNKNOWN		-1

#pragma warning(disable:4996)

int Fibonacci(int n);
int cache[CACHE_MAX] = { 0, };

void main() {

	int n;
	printf("n��° �Ǻ���ġ ? ");
	scanf("%d", &n);
	memset(cache, UNKNOWN, sizeof(cache));

	printf("%d", Fibonacci(n));
}

int Fibonacci(int n) {

	if (n < 2)
		return n;

	if (cache[n] != UNKNOWN)		// ��ȿ�� ĳ���� ���
		return cache[n];			// ����

	int result = Fibonacci(n - 1) + Fibonacci(n - 2);
	cache[n] = result;				// �κ� ���� ĳ�ÿ� ���� ��
	return result;					// ����
}