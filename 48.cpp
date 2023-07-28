#include <iostream>

using namespace std;

int main() {
	constexpr int target = 1000;
	constexpr uint64_t mod = 10000000000;

	int64_t res = 0;
	for (int i = 1; i <= target; i++) {
		int64_t pow = 1;
		for (int j = 0; j < i; j++)
			pow = (pow * i) % mod;
		res = (res + pow) % mod;
	}

	cout << res << endl;
	return 0;
}
