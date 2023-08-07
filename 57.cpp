#include <iostream>

using namespace std;

int main() {
	constexpr int limit = 1000;
	int res = 0;

	string den = "0", num = "1";
	for (int i = 0; i < limit; i++) {
		auto add = [] (string &n1, string &n2) {
			int l2 = n2.length();
			while(l2 > n1.length())
				n1.insert(begin(n1), '0');
			int l1 = n1.length();
			int r = 0, idx = l1 - 1;
			for (int i = 0; i < l1; i++, idx --) {
				if (i >= l2)
					break;
				int d = (n1[idx] - '0') + (n2[l2 - i - 1] - '0') + r;
				r = d / 10;
				d %= 10;
				n1[idx] = d + '0';
			}
			if (r && idx < 0)
				n1.insert(begin(n1), '1');
			else if (r)
				n1[idx] += r;
		};
		auto dbl = [] (string &n) {
			int r = 0, l = n.length();
			for (int i = l; i-- > 0;) {
				int d = (n[i] - '0') * 2 + r;
				r = d / 10;
				n[i] = d % 10 + '0';
			}
			if (r)
				n.insert(begin(n), '1');
		};
		string tmp = den;
		dbl(tmp);
		add(tmp, num);
		num = den;
		den = tmp;

		add(tmp, num);
		if (tmp.length() > den.length())
			res ++;
	}
	cout << res << endl;

	return 0;
}
