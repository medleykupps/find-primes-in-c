#include "stdafx.h"
#include <time.h>

typedef struct 
{
	int value;
	long duration;
} 
Prime;

Prime FindNext(int start) {
	int current = start + 1;
	int index = 2;
	clock_t startClock = clock();
	Prime prime;

//	printf("Finding the next prime after %d\n", start);
	while (true) {
//		printf("  testing %d\n", current);
		bool prime = true;
		while (index <= current / 2) {
			if (current % index == 0) {
				// Found a divisor
				prime = false;
				break;
			}
			index++;
		}
		if (prime) {
			break;
		}
		current++;
	}

	clock_t diff = clock() - startClock;

	prime.value = current;
	prime.duration = (diff * 1000 / CLOCKS_PER_SEC) % 1000;

	return prime;
}

int main()
{
	int primesToFind = 20000;
	int current = 0;
	clock_t mainStart = clock();
	for (int i = 0; i < primesToFind; i++) {
		Prime prime = FindNext(current);
//		printf("Found prime %d in %dms\n", prime.value, prime.duration);
		current = prime.value;
	}
	clock_t mainFinish = clock() - mainStart;
	printf("Found %d primes in %dms\n", primesToFind, (mainFinish * 1000 / CLOCKS_PER_SEC) % 1000);
    return 0;
}
