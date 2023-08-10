#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int num) {
	if (num == 2)
		return true;
	if (!(num % 2))
		return false;
	for (int n = 3; (n * n) <= num; n += 2) {
		if (!(num % n))
			return false;
	}
	return true;
};

int solve(vector<int> &primes, vector<int> &curr, int limit, int depth = 0) {
	int ret = 0;
	if (depth == limit) {
		for (auto &c: curr)
			ret += c;
		return ret;
	}

	auto test = [&curr, &depth] (int p) -> bool {
		if ((depth && p <= curr[depth - 1]))
			return false;
		for (int i = 0; i < depth; i++) {
			auto cnct = [] (int n1, int n2) {
				int m;
				for (m = 1; m <= n2; m *= 10);
	   			return n1 * m + n2;
			};
			int num1 = cnct(curr[i], p);
			int num2 = cnct(p, curr[i]);
			if (!is_prime(num1) || !is_prime(num2))
				return false;
		}
		return true;
	};
	for (auto &p: primes) {
		if (!test(p))
			continue;
		curr[depth] = p;

		int sum = solve(primes, curr, limit, depth + 1);
		if (sum && (!ret || sum < ret))
			ret = sum;
	}
	return ret;
}

int main() {
	constexpr int limit = 5;
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(3);
	auto gen_primes = [&primes] (int limit) {
		if (limit <= primes.back())
			return;
		for (int i = primes.back() + 2;  i <= limit; i += 2) {
			if (is_prime(i))
				primes.push_back(i);
		}
	};

	for (int order = 10;; order *= 10) {
		vector<int> tmp;
		tmp.resize(limit, 0);

		gen_primes(order);
		int sum = solve(primes, tmp, limit);

		if (sum) {
			cout << "Order: " << order << " sum: " << sum << endl;
			break;
		}
	}

	return 0;
};
