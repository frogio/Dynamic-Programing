#include <stdio.h>
#include <memory.h>

#define CACHE_MAX	1000
#define UNKNOWN		-1

#pragma warning(disable:4996)

int Fibonacci(int n);
int cache[CACHE_MAX] = { 0, };

void main() {

	int n;
	printf("n번째 피보나치 ? ");
	scanf("%d", &n);
	memset(cache, UNKNOWN, sizeof(cache));

	printf("%d", Fibonacci(n));
}

int Fibonacci(int n) {

	if (n < 2)
		return n;

	if (cache[n] != UNKNOWN)		// 유효한 캐시일 경우
		return cache[n];			// 리턴

	int result = Fibonacci(n - 1) + Fibonacci(n - 2);
	cache[n] = result;				// 부분 합을 캐시에 저장 후
	return result;					// 리턴
}