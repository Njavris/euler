#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	constexpr int limit = 28123;
	int r = 0;
	vector<int> abdts, numbers;

	auto abundance = [] (int n) mutable -> int {
		int r = 1;
		for (int i = 2; i <= n / 2; i++)
			if (!(n % i))
				r += i;
		return r - n;
	};

	for (int i = 1; i <= limit; i++) {
		if (abundance(i) > 0)
			abdts.push_back(i);
	}

	numbers.resize(limit, 0);

	for (int i = 0; i < abdts.size(); i++) {
		for (int j = 0; j < abdts.size(); j++) {
			int n = abdts[i] + abdts[j];
			if (n <= limit)
				numbers[n] = 1;
		}
	}

	for (int i = 0; i < numbers.size(); r += !numbers[i] ? i : 0, i++);
	cout << r << endl;
	return 0;
}
