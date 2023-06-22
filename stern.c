#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef ALL_STERN
#define ALL_STERN	0
#endif

int main() {
#define LIMIT    10000000
	uint64_t *primes = (uint64_t *)calloc(LIMIT + 1, sizeof(uint64_t));
	primes[0] = 2;
	for (uint64_t i = 2, pr = 0, f = 0, p_cnt = 1; p_cnt < LIMIT; (i += i % 2 ? 2 : 1) && (pr = f = 0)) {
		for (uint64_t j = 0; j < p_cnt && !pr; pr = !(i % primes[j++]));
		if (!pr) {
			primes[p_cnt++] = i;
		}
		for (uint64_t j = 0; j < p_cnt; j++) {
			uint64_t sq = (i - primes[j]) / 2;
			uint64_t rt = sqrtl((long double)sq);
			if ((ALL_STERN && !sq) || (rt * rt != sq)) continue;
//			printf("%lu = %lu + 2 * %lu (%lu^2)\n", i, primes[j], sq, rt);
			f = 1;
			break;
		}
		if (!f)
			printf("################Found: %lu\n", i);
		if (!(i % 1000000))
			printf("%lu\n", i);
	}
	free(primes);
	return 0;
}
