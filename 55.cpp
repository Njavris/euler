#include <iostream>

using namespace std;

bool solve(string &num, int depth, int first = true) {
	bool isPal = true;
	string res;
	int r = 0;
	int l = num.length();
	for (int i = l; i -- > 0;) {
		int d1 = num[i] - '0';
		int d2 = num[l - i - 1] - '0';
		if (d1 != d2)
			isPal = false;
		int d = d1 + d2 + r;
		r = d / 10;
		d %= 10;
		res.push_back(d + '0');
	}
	if (r)
		res.push_back(r + '0');
	if (isPal && !first)
		return false;
	if (!depth)
		return true;
	return solve(res, depth - 1, false);
}

int main() {
	constexpr int limit = 10000;
	constexpr int max_depth = 50;
	int res = 0;

	for (int i = 1; i <= limit; i++) {
		string n = to_string(i);
		if (solve(n, max_depth))
			res ++;
	}
	cout << res << endl;
	return 0;
}
