#include <stdio.h>

int main() {
#define LIMIT	10001
	int primes[LIMIT];
	for (int cnt = 0, pr = 0, curr = 2; cnt < LIMIT;(curr += (curr % 2) ? 2 : 1) && (pr = 0)) {
		for (int i = 0; i < cnt && !pr; pr = !(curr % primes[i++]));
		if (!pr)
			primes[cnt++] = curr;
	}
	printf("%d\n", primes[LIMIT - 1]);
	return 0;
}
