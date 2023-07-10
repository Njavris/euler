#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

/*
	P = (2n)! / (n! * n!) = Prod(k = n + 1 .. 2n, k) / n!
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
	for (int i = 1; i <= limit; i++) {
		muls.push_back(i + limit);
		divs.push_back(i);
	}
	for (auto &m: muls) {
		r *= m;
		for (int i = 0; i <= divs.size();) {
			if (divs[i] > 1 && divs[i] <= r && !(r % divs[i])) {
				r /= divs[i];
				divs.erase(divs.begin() + i);
				continue;
			}
			i++;
		}
	}
	cout << r << endl;
	return 0;
}
