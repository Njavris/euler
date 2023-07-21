#include <iostream>

using namespace std;

void solve(int tgt, int sz, int *set, int &res, int* curr, int curr_sum = 0, int depth = 8) {
	if (curr_sum == tgt)
		res++;
	if (curr_sum >= tgt || !depth)
		return;
	int c = set[sz - depth];
	for (int i = 0; i <= tgt / c; i++) {
		curr[8 - depth] = i;
		solve(tgt, sz, set, res, curr, curr_sum + i * c, depth - 1);
	}
}

int main() {
	int coins[] = { 200, 100, 50, 20, 10, 5, 2, 1};
	int curr[sizeof(coins)/sizeof(coins[0])];
	int sz = sizeof(coins)/sizeof(coins[0]), res = 0;

	constexpr int target = 200;

	solve(target, sz, coins, res, curr);
	cout << res << endl;

	return 0;
}
