#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main() {
	int cnt = 0, target = 10001;
	uint32_t num = 2;
	uint32_t *primes = (uint32_t *)malloc(target * sizeof(uint32_t));
	memset(primes, 0, target * sizeof(uint32_t));

	while (cnt < target) {
		int is_prime = 1;
		for (int i = 0; i < cnt; i++) {
			if (!(num % primes[i])) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime)
			primes[cnt++] = num;
		num += (num % 2) ? 2 : 1;
	}
	printf("%d %d\n", num, primes[target - 1]);
	return 0;
}
