#include <iostream>
#include <vector>

using namespace std;

int main() {
	constexpr int problem = 4;
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(3);

	auto is_prime = [&primes] (int num) {
		int curr = primes.back() + 2;
		for (;curr <= num; curr += 2) {
			bool pr = true;
			for (auto &p: primes) {
				if (!(curr % p)) {
					pr = false;
					break;
				}
			}
			if (pr) {
				primes.push_back(curr);
				if (curr == num)
					return true;
			}
		}
		return false;
	};
	auto cnt_divs = [&primes, &is_prime] (int num) -> int {
		int cnt = 0;
		if (is_prime(num))
			return cnt;

		for (auto &p: primes) {
			if (p * p > num)
				break;
			if (num % p)
				continue;
			cnt ++;
			while (!(num % p))
				num /= p;
		}
		if (num != 1)
			cnt ++;
		return cnt;
	};

	int res, n = problem;
	vector<int> cnt;
	for (int i = 0; i < problem; cnt.push_back(cnt_divs(i++)));

	while (++n > 0) {
		int i = 0;
		for (; cnt[i] == problem && i < problem; i++);
		if (i == problem) {
			res = n - problem;
			break;
		}

		cnt.erase(begin(cnt));
		cnt.push_back(cnt_divs(n));
	}
	cout << res << endl;

	return 0;
}
