#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int>> &numbers, vector<vector<int>> &res,
			vector<int> &curr, vector<int> &figs, int limit, int depth = 0) {
	if (depth == limit) {
		if (((curr[0] / 100) == (curr[limit - 1] % 100))) {
			sort(begin(curr), end(curr));
			if (find(begin(res), end(res), curr) == end(res))
				res.push_back(curr);
		}
		return;
	}

	for (int i = 0; i < limit; i++) {
		if ( [&i, &curr, &figs, &depth]() {
			for (int j = 0; j < depth; j++)
				if (figs[j] == i)
					return true;
			return false;
		}())
			continue;

		auto &v = numbers[i];
		figs[depth] = i;
		for (auto &e: v) {
			if (depth && ((e / 100) != (curr[depth - 1] % 100)))
				continue;
			curr[depth] = e;
			solve(numbers, res, curr, figs, limit, depth + 1);
		}
	}
};

int main() {
	constexpr int limit = 6;
	int (*figurates[])(int) = {
		[] (int n) { return n * (n + 1) / 2; },		// 3
		[] (int n) { return n * n; },			// 4
		[] (int n) { return n * (3 * n - 1) / 2; },	// 5
		[] (int n) { return n * (2 * n - 1); },		// 6
		[] (int n) { return n * (5 * n - 3) / 2; },	// 7
		[] (int n) { return n * (3 * n - 2); },		// 8
	};

	vector<vector<int>> numbers;
	vector<vector<int>> res;
	numbers.resize(limit, vector<int>());

	for (int i = 0; i < limit; i++) {
		for (int n = 1;; n++) {
			int p = figurates[i](n);
			if ((p / 1000) == 0)
				continue;
			if (p >= 10000)
				break;
			numbers[i].push_back(p);
		}
	}

	vector<int> t1, t2;
	t1.resize(limit, 0);
	t2.resize(limit, 0);
	solve(numbers, res, t1, t2, limit);

	for (auto &v: res) {
		int sum = 0;
		for (auto &n: v) {
			cout << n << " ";
			sum += n;
		}
		cout << endl << "Sum: " << sum << endl;
	}

	return 0;
};
