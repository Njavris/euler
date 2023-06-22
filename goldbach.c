#include <stdio.h>
#include <math.h>

int main() {
#define LIMIT	1000
	int primes[LIMIT + 1];
	for (int cnt = 0, pr = 0, curr = 2; cnt < LIMIT + 1; (curr += (curr % 2) ? 2 : 1) && (pr = 0)) {
		for (int i = 0; i < cnt && !pr; pr = !(curr % primes[i++]));
		if (!pr) primes[cnt++] = curr;
	}
	for (int i = 3, f = 0, pr = 0; i < primes[LIMIT]; (i += 2) && (pr = f = 0)) {
		for (int j = 0; (j < LIMIT) && (i >= primes[j]); j++)
			if (primes[j] == i)
				pr = 1;
		if (pr) continue;
		for (int j = 0; (j < LIMIT) && (i >= primes[j]); j++) {
			int sq = (i - primes[j]) / 2;
			int rt = sqrt((double)sq);
			if (rt * rt != sq) continue;
//			printf("%d = %d + 2 * %d^2\n", i, primes[j], rt);
			f = 1;
		}
		if (!f) {
			printf("Answer = %d\n", i);
			break;
		}
	}
	return 0;
}
