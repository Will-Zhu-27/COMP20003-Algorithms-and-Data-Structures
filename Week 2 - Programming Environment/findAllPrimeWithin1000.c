#include <stdio.h>
#include <stdlib.h>

#define PRIMECOUNT 1000

void sieveOfEratosthenes(int *n, int number);

int main(int argc, char **argv){
	/* The primes 1 - 1000, if n is prime,
	primes[n - 1] == 1 and 0 otherwise. */
	int primes[PRIMECOUNT];
	int i;
	for(i = 0; i < PRIMECOUNT; i++){
		primes[i] = 1;
	}
	/* Write a prime checking algorithm here. */
	sieveOfEratosthenes(primes, PRIMECOUNT);
	/* -------------------------------------- */
	printf("All primes found from 1 - 1000:\n");
	for(i = 0; i < PRIMECOUNT; i++){
		if(primes[i] == 1){
		printf("%d\t",i + 1);
		}
	}
	printf("\n");
	return 0;
}

void sieveOfEratosthenes(int *n, int number) {
	int i = 0, j = 0, k = 2;
	n[0] = 0;
	for (i = 1; i < number; i++) {
		if (n[i] == 0) {
			continue;
		}
		for (j = i, k = 2; (j + 1) * k <= number; k++) {
			n[(j + 1) * k - 1] = 0;
		}
	}
}
