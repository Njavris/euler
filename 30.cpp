#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(vector<int> &pows, vector<int> &curr, vector<int> &r, int depth = 6) {
	if (depth < 0)
		return;

	for (int i = 0; i < 10; i++) {
		string s;
		int val, sum = 0;

		if (!i && !curr.size())
			continue;

		curr.push_back(i);

		solve(pows, curr, r, depth - 1);

		for (auto &c: curr)
			s.push_back(c + '0');
		val = stoi(s);
		for (auto &c: curr)
			sum += pows[c];

		if (sum > 1 && sum == val)
			r.push_back(val);

		curr.pop_back();
	}
	return;
}

int main() {
	int ret = 0;
	vector<int> pows, curr, res;

	for (int i = 0; i < 10; i++)
		pows.push_back(i * i * i * i * i);

	solve(pows, curr, res);
	for (auto &v: res)
		ret += v;

	cout << ret << endl;

	return 0;
}
