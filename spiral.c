#include <stdio.h>

int calc_res(int width) {
	int sum = 1;
	for (int i = 2; i <= (width + 1) / 2; i++)
		sum += 16 * i * i - 28 * i + 16;
	return sum;
}

int main() {
#define WIDTH	1001
	printf("sum = %d\n", calc_res(WIDTH));
	return 0;
}
