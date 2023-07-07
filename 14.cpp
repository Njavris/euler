#include <iostream>
#include <vector>

using namespace std;

int main(int c, char **v) {
	int limit = 1000000;
	vector<int> n_n;
	int best = 0;
	int best_n = 0;
	n_n.resize(limit, 0);

	auto collatz_n = [&n_n, &limit] (int num) -> int {
		int r = 0;
		uint64_t n = num;
		while (n != 1) {
			if (n < limit && n_n[n]) {
				r += n_n[n];
				break;
			}
			n = !(n % 2) ? n / 2 : n * 3 + 1;
			r++;
		}
		return r;
	};

	for (int i = 1; i < limit; i++) {
		n_n[i] = collatz_n(i);
		if (n_n[i] > best_n) {
			best_n = n_n[i];
			best = i;
		}
	}

	cout << best << endl;
	return 0;
}
