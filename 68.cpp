#include <iostream>
#include <vector>

using namespace std;

#define LIMIT		5
#define LIMIT_CNT	10

void solve(vector<uint64_t> &results, vector<int> &curr, int depth = 0) {
	if (curr.size() == depth) {
		int s = 0;
		for (int i = 0; i < LIMIT; i++) {
			int sum = curr[i];
			sum += curr[LIMIT + i];
			sum += curr[LIMIT + ((i + 1) % LIMIT)];
			if (!s) {
				s = sum;
				continue;
			}
			if (s != sum)
				return;
		}

		string r;
		for (int i = 0; i < LIMIT; i++) {
			r += to_string(curr[i]);
			r += to_string(curr[LIMIT + i]);
			r += to_string(curr[LIMIT + ((i + 1) % LIMIT)]);
		}
		results.push_back(strtoul(r.c_str(), NULL, 10));
		return;
	}
	if (depth == LIMIT) {
		if (find(begin(curr), end(curr), 10) == end(curr))
			return;
		for (int i = 1; i < LIMIT; i++) {
			if (curr[i] < curr[0])
				return;
		}
	}
	for (int i = 1; i <= LIMIT_CNT; i++) {
		if (find(begin(curr), end(curr), i) != end(curr))
			continue;
		curr[depth] = i;

		solve(results, curr, depth + 1);
		curr[depth] = 0;
	}
}

int main() {
	uint64_t res = 0;

	vector<uint64_t> ret;
	vector<int> curr;
	curr.resize(LIMIT_CNT);

	solve(ret, curr);

	for (auto &r: ret)
		if (r > res)
			res = r;
	cout << res << endl;

	return 0;
}
