/* Prime numbers are fairly useful on their ow n, 
but another fun challenge is to find w hat are know n
as emirp primes. Emirp primes are primes w hich are also 
primes w hen reversed. For this challenge, you need to 
print out the list of all primes that are also primes 
(as defined in the challenge above) w hen reversed from 1 - 1000.
*/
#include <stdio.h>
#include <stdlib.h>

#define PRIMECOUNT 1000

void sieveOfEratosthenes(int *n, int number);
void emirp(int *n, int number);
int reverse(int n);

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
	//printf("%d\n", primes[6]);
	
	emirp(primes, PRIMECOUNT);
	//printf("%d\n", primes[6]);
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

void emirp(int *n, int number) {
	int i = 0;
	for (i = 0; i < number; i++) {
		if (!(n[i] == 1 && n[reverse(i + 1) - 1] == 1)) {
			n[i] = 0;
			//n[reverse(i + 1) - 1] = 0;
		}
	}
}

int reverse(int n) {
	int reverseNumber = 0, temp = 0;
	while (n != 0) {
		temp = n % 10;
		n = n / 10;
		reverseNumber = reverseNumber * 10 + temp;
	}
	return reverseNumber;
}
