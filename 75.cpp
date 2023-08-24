#include <iostream>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	constexpr int limit = 1500000;
	vector<int> lens;
	lens.resize(limit, 0);
	for (int m = 2;m <= sqrt(limit / 2) + 1; m++) {
		for (int n = 1; n < m; n++) {
			if (!((m + n) % 2) ||  gcd(m, n) != 1)
				continue;
			int l = (m + n) * m * 2;
			for (int k = 1; k * l <= limit; lens[k++ * l] += 1);
		}
	}
	cout << count(begin(lens), end(lens), 1) << endl;
	return 0;
}
