#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int limit = 10000;
	int r = 0;
	vector <int> amicables, sums;

	auto divisor_sum = [] (int n) -> int {
		int r = 0;
		for (int i = 1; i <= n / 2; r += n % i ? 0 : i, i++);
		return r;
	};

	sums.resize(limit, 0);

	for (int i = 2; i <= limit; i++) {
		int &s = sums[i];
		if (!s)
			s = divisor_sum(i);
		if (s > limit)
			continue;
		if (!sums[s])
			sums[s] = divisor_sum(s);
		if (sums[s] == i && s != i)
			amicables.push_back(i);
	}

	for_each(amicables.begin(), amicables.end(), [&r] (int n) { r+= n; });

	cout << r << endl;
	return 0;
}
