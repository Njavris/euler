#include <iostream>
#include <vector>

using namespace std;

void gen_primes(vector<int> &primes, int limit, int cnt = 0) {
	if (!primes.size()) {
		primes.push_back(2);
		primes.push_back(3);
	}

	for (int pr = primes.back() + 2; pr <= limit || primes.size() < cnt; pr += 2) {
		bool is_prime = true;
		for (int n = 3; is_prime && n * n <= pr; is_prime = (pr % n), n += 2);
		if (is_prime)
			primes.push_back(pr);
	}
}

int comb_for_num(vector<int> &primes, int num, int curr = 0) {
	if (!num)
		return 1;
	if (!primes.size() || primes.back() < num)
		gen_primes(primes, 2 * num);

	int ret = 0;
	for (int i = curr; primes[i] <= num && i < primes.size(); i++)
		ret += comb_for_num(primes, num - primes[i], i);
	return ret;
}

int main() {
	constexpr int target = 5000;
	vector<int> primes;

	for (int i = 0;;) {
		int cnt = comb_for_num(primes, ++i);
		if (cnt >= target) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
