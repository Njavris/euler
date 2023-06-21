#include <stdio.h>

int main() {
	for (int a = 1; a < 500; a++) {
		for (int b = 1; b < 1000 - a; b++) {
			int c = 1000 - a - b;
			if (((a * a) + (b * b)) == (c * c))
				printf("%d * %d * %d = %d\n", a, b, c, a * b * c);
		}
	}
	return 0;
}
