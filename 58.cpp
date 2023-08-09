#include <iostream>
#include <vector>

using namespace std;

int main() {
	auto is_prime = [] (int num) -> bool {
		if (!(num % 2))
			return false;
		if (num == 2)
			return true;
		for (int n = 3; (n * n) <= num; n += 2) {
			if (!(num % n))
				return false;
		}
		return true;
	};

	int corner_primes = 0;
	int corner_cnt = 1;
	int res = 0;

	for (int i = 1, off = 1;; i++) {
		for (int j = 1; j <= 4; j++) {
			off += 2 * i;
			corner_cnt ++;
			if (is_prime(off))
				corner_primes ++;
		}
		if (corner_cnt > 10 * corner_primes) {
			res = i * 2 + 1;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
