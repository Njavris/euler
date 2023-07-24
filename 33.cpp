#include <iostream>

using namespace std;

int main() {
	int prod_num = 1;
	int prod_den = 1;
	int muls[][4] = {{10, 1, 10, 1},
			{10, 1, 1, 10},
			{1, 10, 10, 1},
			{1, 10, 1, 10}};
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				double tgt = (double)j / k;
				if (j == k || j > k)
					continue;
				for (int l = 0; l < sizeof(muls) / sizeof(muls[0]); l++) {
					int num = i * muls[l][0] + j * muls[l][1];
					int den = i * muls[l][2] + k * muls[l][3];
					double val = (double)num / den;
					if (val == tgt) {
						prod_num *= num;
						prod_den *= den;
					}
				}
			}
		}
	}
	cout << prod_den / prod_num << endl;

	return 0;
}
