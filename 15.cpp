#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;


/*
	P = (2n)! / (n! * n!) = (2n)! /(n!)^2
*/

int64_t fact(int64_t i) { return i * ((i == 1) ? 1 : fact(i - 1)); }

int main(int c, char **v) {
	int limit = 20;
	int64_t res = fact(limit + limit);
	res /= fact(limit)*fact(limit);
	cout << res << endl;

	vector<int> muls;
	vector<int> divs;
	int64_t r = 1;
	for (int i = 1; i <= 2 * limit; i++) {
		muls.push_back(i);
		if (i <= limit)
			divs.push_back(i * i);
	}
	for (int i = 0; i < muls.size(); i++) {
		r *= muls[i];
		for (int j = 0; j < divs.size(); j++) {
			if (divs[j] > 1 && divs[j] <= r && !(r % divs[j])) {
				r /= divs[j];
				divs[j] = 1;
			}
		}
	}
	cout << r << endl;
	return 0;
}
