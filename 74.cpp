#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int fact(int n) {
	return !n ? 1 : n * fact(n - 1);
}

static int num_sum(vector<int> &facts, int n) {
	int ret = 0;
	for (;n; n /= 10) ret += facts[n % 10];
	return ret;
};

static bool solve(vector<int> &curr, int n, int target, vector<int> &facts) {
	int val = num_sum(facts, n);
	if (curr.size() > target)
		return false;
	if (find(begin(curr), end(curr), val) == end(curr)) {
		if (curr.size() >= target) {
			return false;
		} else {
			curr.push_back(val);
			return solve(curr, val, target, facts);
		}
	} else if (curr.size() == target) {
		return true;
	}
	return false;
};

int main() {
	constexpr int limit = 1000000;
	constexpr int target = 60;
	vector<int> facts, tmp;
	for (int i = 0; i <= 9; i++)
		facts.push_back(fact(i));

	int res = 0;
	for (int i = 1; i < limit; i++) {
		tmp.clear();
		tmp.push_back(i);
		if (solve(tmp, i, target, facts))
			res ++;
	}
	cout << res << endl;

	return 0;
}
