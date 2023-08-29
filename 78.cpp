#include <iostream>
#include <vector>

using namespace std;

int P(int n) {
static vector<int> cache;
	if (!n)
		return 1;
	if (n < 0)
		return 0;

	if (cache.size() <= n) {
		cache.resize(2 * n, 0);
	}
	if (cache[n] > 0)
		return cache[n];
	int res = 0;
	for (int k = 1; ((3 * k * k - k) / 2) <= n; k++) {
		int n1 = n - k * (3 * k - 1) / 2;
		int n2 = n - k * (3 * k + 1) / 2;
		int pk = 0;
		if (n1 > 0) {
			if (cache[n1] > 0)
				pk += cache[n1];
			else
				pk += P(n1);
		} else if (!n1) {
			pk ++;
		}
		if (n2 > 0) {
			if (cache[n2] > 0)
				pk += cache[n2];
			else
				pk += P(n2);
		} else if (!n2) {
			pk ++;
		}
		if (!(k % 2))
			pk *= -1;
		res += pk;
	}
	res = (res % 1000000 + 1000000) % 1000000;
	cache[n] = res;
	return res;
}

int main() {
	int n = 1;
	for (;P(n);n++);
	cout << n << endl;
	return 0;
}
