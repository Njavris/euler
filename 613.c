#include <stdio.h>
#include <math.h>


int main() {
	double res = 0;

	int deltas = 100000;
	double dx = 30.0 / deltas;
	double dy = 40.0 / deltas;

	for (int i = 0; i < deltas; i++) {
		double x = i * dx;
		double limit = 40. - (40. / 30.) * x;
		for (int j = 0; j < deltas; j++) {
			double y = j * dy;
			if (y >= limit)
				break;
			res += (3.0 * M_PI) / 2.0;
			res -= atan((40. - y) / x);
			res -= atan((30. - x) / y);
//			printf("x:%f y:%f th:%f\n", x, y, tmp);
		}
	}
	res *= dx * dy;
	res /= 1200 * M_PI;
	printf("result:  %.10f\n", res);
	printf("Correct: 0.3916721504\n");
	return 0;
};
