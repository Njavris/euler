#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
	int32_t res = 0;
	for (int32_t j, l, i = 0; i < 1000000; i++) {
		int msb = 31 - __builtin_clz(i);
		char s[7];
		int32_t r = 0;

		/* decimal */
		sprintf(s, "%d", i);
		l = strlen(s) - 1;
		for (j = 0; j <= l; j++)
			if (s[j] != s[l - j])
				break;
		if (j < l)
			continue;

		/* binary */
		for (j = 0; j <= msb; j++)
			r |= ((i >> j) & 1) << (msb - j);
		if (i == r)
			res += i;
	}
	printf("sum = %d\n", res);
	return 0;
}
