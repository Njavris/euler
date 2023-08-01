#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	constexpr int limit = 8;
	vector<int> primes;

	primes.push_back(2);
	primes.push_back(3);
	auto gen_primes = [&primes] (int limit) {
		for (int i = primes.back(), nprime = 0; i <= limit; i += 2, nprime = 0) {
			for (int j = 0; !nprime && j < primes.size(); nprime = !(i % primes[j++]));
			if (!nprime)
				primes.push_back(i);
		}
	};
	auto is_prime = [&primes, &gen_primes] (int n) -> bool {
		for (int i = 0; i < primes.size() && primes[i] <= n; i++)
			if (primes[i] == n)
				return true;
		return false;
	};

	auto dgts = [] (int num) -> int {
		int r = 0;
		for (; num; r++, num /= 10);
		return r;
	};

	auto msb = [] (unsigned mask) -> int {
		int r = 0;
		for (; mask; r++, mask >>= 1);
		return r;
	};

	auto num_primes_mask = [&is_prime, &dgts, &msb] (int num, unsigned mask) -> int {
		int ret = 0, b = msb(mask);
		for (int i = 0; i <= 9; i++) {
			unsigned msk = mask;
			int n = 0;
			for (int m = 1; num / m; m *= 10, msk >>= 1)
				n += m * (msk & 1 ? i : (num / m) % 10);
			if (!i && b > dgts(n))
				continue;
			ret += is_prime(n);
		}
		return ret;
	};

	auto gen_mask = [] (int num) -> unsigned {
		unsigned ret = 0;
		int dg = -1;
		for (int o = 1, n = num / 10; n; o++, n /= 10) {
			int d = n % 10;
			if (dg < 0)
				dg = d;
			else if (d != dg && d)
				return 0;
			if (d == dg)
				ret |= 1 << o;
		}
		return ret;
	};

	auto dxor = [] (int n1, int n2) -> int {
		int ret = 0;
		int mul = 1;
		int dg = -1;
		while (n1) {
			mul *= 10;
			n1 /= 10;
			n2 /= 10;
			int d1 = n1 % 10;
			int d2 = n2 % 10;
			if (d1 != d2) {
				if (dg < 0)
					dg = d2;
				if (d2 != dg)
					return 0;
				ret += d1 * mul;
			}
		}
		return ret;
	};

	gen_primes(1000000);

	for (int i = 0; i < primes.size(); i++) {
		int dg = dgts(primes[i]);
		for (int j = i + 1; j < primes.size(); j++) {
			if (dgts(primes[j]) != dg)
				break;
			if (primes[i] % 10 != primes[j] % 10)
				continue;
			int delta = dxor(primes[i], primes[j]);
			if (!delta)
				continue;
			unsigned mask = gen_mask(delta);
			if (!mask)
				continue;
			int cnt = num_primes_mask(primes[i], mask);
			if (cnt == limit) {
				cout << primes[i] << endl;
				return 0;
			}
		}
	}

	return 0;
}
