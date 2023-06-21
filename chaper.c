#include <stdio.h>
#include <string.h>

int main() {
	int i = 1, res = 1;
	while ((i *= 10) <= 1000000) {
		char str[8];
		int o, curr, e, r, pr;
		for (curr = o = e = 1, pr = 0; o < 7; o++ && (e*= 10) && (curr = pr + 1)) {
			pr += 9 * e * o;
			if (i >= curr && i <= pr)
				break;
		}
		sprintf(str, "%d", e + (i - curr) / o);
		res *= str[(i - curr) % o] - '0';
	}
	printf("sum = %d\n", res);

	return 0;
}
