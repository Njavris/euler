#include <iostream>

using namespace std;

void solve(string &num, string &curr, int &best, int pow) {
	string res;
	if (!curr.length()) {
		res = num;
		pow --;
	}

	int l1 = num.length();
	int l2 = curr.length();
	for (int i = l1; i -- > 0;) {
		int d1 = num[i] - '0';
		for (int j = l2; j -- > 0;) {
			string t1, t2;
			int r = 0;
			int d = d1 * (curr[j] - '0');
			t1.insert(begin(t1), (d % 10) + '0');
			if (d / 10)
				t1.insert(begin(t1), (d / 10) + '0');
			if (!res.length()) {
				res = t1;
				continue;
			}
			int idx, sh = l2 - j - 1 + l1 - i - 1;
			int lt = t1.length();
			while (res.length() < lt + sh)
				res.insert(begin(res), '0');
			int lr = res.length();
			t2 = res;
			r = 0;
			for (int k = 0; k < lt; k ++) {
				idx = lr - k - 1 - sh;
				int d = (t2[idx] - '0') + (t1[lt - k - 1] - '0') + r;
				r = d / 10;
				res[idx] = d % 10  + '0';
			}
			if (r && !idx)
				res.insert(begin(res), r + '0');
			else if (r)
				res[idx - 1] += r;
		}
	}

	int sum = 0;
	for (auto &c: res)
		sum += c - '0';
	if (sum > best)
		best = sum;

	if (pow)
		solve(num, res, best, pow - 1);
}

int main() {
	constexpr int limit = 100;
	int best = 0;

	for (int a = 1; a < limit; a++) {
			string tmp, n = to_string(a);
			solve(n, tmp, best, limit - 1);
	}
	cout << best << endl;

	return 0;
}
