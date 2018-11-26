#include <stdio.h>

int isPrime(int n);
int main(int argc, char **argv) {
	int n;
	while(scanf("%d", &n)==1) {
		if (isPrime(n) == 0) {
			printf("%d is not a prime number!\n", n);
		} else {
			printf("%d is a prime number!\n", n);
		}
	}
	return 0;
}

int isPrime(int n) {
	int divisor = 2;
	if (n <2) {
		return 0;
	}
	for (divisor = 2; divisor * divisor < n; divisor++) {
		if (n%divisor == 0) {
			return 0;
		}
	}
	return 1;
}
