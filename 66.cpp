#include <iostream>
#include <vector>
#include <cmath>
#include "string_math.h"

using namespace std;

/*
x^2 - D * y^2 = 1

x, y - integers

(x * x - 1) / D = y * y - integer

D = h / k

x^2 = 1 + (h / k) * y^2
k * (x^2 - 1) = h * y ^ 2;
9 * 9 = 1 + 5 * 4 * 4
81
*/


int main() {
	constexpr int limit = 1000;
//	constexpr int limit = 7;

	int longest = 0;

	int closest = 1;
	int next = (closest + 1) * (closest + 1);
	for (int i = 2; i <= limit; i++) {
		if (next == i) { // To avoid sqrt
			closest ++;
			next = (closest + 1) * (closest + 1);
		}
		if (closest * closest == i)
			continue;

		vector<int> as;
		for (int d = 1, m = 0, a = 0;;) {
			m = d * a - m;
			d = (i - m * m) / d;
			a = (closest + m) / d;
			as.push_back(a);

			int sz = as.size();
			string num = to_string(as.back());
			string den = "1";
			for (int k = sz - 2; k > 0; k --) {
				string tmp, a = to_string(as[k]);
				str_mul(num, a, tmp);
				str_add(tmp, den);
				den = num;
				num = tmp;
			}
			if (num == "0" || den == "0")
				continue;

			string left, right, tmp = to_string(i);
			string den2, tmp1 = num;
			str_mul(tmp1, num, left);
			str_mul(den, den, den2);
			str_mul(den2, tmp, right);
			tmp = to_string(1);
			str_add(right, tmp);

			if (left == right) {
				if (num.length() >= longest) {
					longest = num.length();
					cout << i << " " << num << endl;
				}
				break;
			}
		}
	}

	return 0;
};
