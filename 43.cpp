#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(uint64_t &res, int *set, int set_sz, int *curr,
			int curr_sz, auto func, int depth = 0) {
	if (depth == set_sz) {
		res += func(curr, curr_sz);
		return;
	}

	for (int i = 0; i < set_sz; i++) {
		bool found = false;
		for (int j = 0; j < depth; j++)
			if (curr[j] == set[i]) {
				found = true;
				break;
			}
		if (found)
			continue;
		curr[depth] = set[i];
		solve(res, set, set_sz, curr, curr_sz, func, depth + 1);
	}
}

int main() {
	uint64_t res = 0;
	int c[10] = { -1 };
	int set[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	solve(res, set, sizeof(set) / sizeof(set[0]), c, sizeof(c) / sizeof(c[0]),
		[] (int *c, int c_sz) -> uint64_t {
			int nums[] = { 2, 3, 5, 7, 11, 13, 17 };
			string s;
			for (int i = 0; i < c_sz; i++)
				s.push_back(c[i] + '0');
			for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
				int *tmp = &c[i + 1];
				int t = tmp[0] * 100 + tmp[1] * 10 + tmp[2];
				if (t % nums[i])
					return 0;
			}
			return stol(s);
		});

	cout << res << endl;
	return 0;
};
