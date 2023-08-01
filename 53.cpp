#include <iostream>
#include <vector>

using namespace std;

int main() {
	constexpr int limit = 1000000;
	constexpr int bounds = 100;
	auto comb = [] (int n, int r) -> int64_t {
		int64_t res = 1;
		vector<int> muls, divs;
		for (int i = r + 1; i <= n; muls.push_back(i++));
		for (int i = 1; i <= n - r; divs.push_back(i++));

//		for (auto &m: muls) {
//			for (auto &d: divs) {
//				if (d > 1 && !(m % d)) {
//					m = m / d;
//					d = 1;
//				}
//			}
//		}

		for (auto &m: muls) {
			res *= m;
			for (auto &d: divs) {
				if (d > 1 && d <= res && !(res % d)) {
					res /= d;
					d = 1;
				}
			}
		}
		return res;
	};

	int res = 0;
	for (int i = 1; i <= bounds; i++) {
		for (int j = 1; j <= i; j++) {
			int c = comb(i, j);
			if (c >= limit || c < 0)
				res ++;
		}
	}
	cout << res << endl;

	return 0;
}
