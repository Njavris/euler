#include <iostream>

using namespace std;

static int solve(const int target, const int sum = 0, const int num = 0) {
	int res = 0;
	if (sum >= target || num == target) {
		if (sum == target)
			res++;
		return res;
	}
	for (int i = 0; i <= target / (num + 1); i++)
		res += solve(target, sum + i * (num + 1), num + 1);
	return res;
}

int P(int n) {
static int cache[100] = { 0 };
	if (!n)
		return 1;

	if (cache[n] > 0)
		return cache[n];
	int res = 0;
	for (int k = 1; k * k <= n; k++) {
		int n1 = n - k * (3 * k - 1) / 2;
		int n2 = n - k * (3 * k + 1) / 2;
		int pk = 0;
		if (n1 >= 0)
			pk += P(n1);
		if (n2 >= 0)
			pk += P(n2);
		if (!(k % 2))
			pk *= -1;
		res += pk;
	}
	cache[n] = res;
	return res;
}

int main() {
	constexpr int limit = 100;
	cout << P(limit) << endl;
	cout << solve(limit) << endl;
	return 0;
}
