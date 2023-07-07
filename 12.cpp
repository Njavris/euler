#include <iostream>
#include <vector>

using namespace std;

int main(int c, char **v) {
	int t_n = 2, p_cnt = 100, limit = 500;
	vector<int> primes;
	auto div_n = [&primes] (int n) -> int {
		int ret = 1;
		for (auto &p: primes) {
			int c = 0;
			while (!(n % p)) {
				n /= p;
				c++;
			}
			ret *= c + 1;
		}
		return ret;
	};

	primes.push_back(2);
	for (int i = 3, isPr = 1; i < p_cnt; i += 2, isPr = 1) {
		for (auto &p: primes)
			if (!(isPr = i % p))
				break;
		if (isPr)
			primes.push_back(i);
	}

	for (int c = 0, odd = 1, even = 1; c < limit;) {
		if (!(t_n % 2))
			even = div_n(++t_n);
		else
			odd = div_n(++t_n / 2);
		c = odd * even;
	}
	t_n *= t_n - 1;
	t_n /= 2;
	cout << t_n << endl;
	return 0;
}
