#include <iostream>

using namespace std;

int main() {
	auto str_add = [] (string &n1, string &n2) {
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
	auto str_mul = [&str_add] (string &n1, string &n2, string &ret) {
		ret.clear();
		for (int i = n2.length(), off = 0; i-- > 0; off ++) {
			string tmp;
			int r = 0, d2 = n2[i] - '0';
			for (int j = n1.length(); j-- > 0;) {
				int d1 = n1[j] - '0';
				int d = d1 * d2 + r;
				r = d / 10;
				d %= 10;
				tmp.insert(begin(tmp), d + '0');
			}
			if (r)
				tmp.insert(begin(tmp), r + '0');
			for (int j = 0; j < off; j++)
				tmp.push_back('0');
			if (!off) {
				ret = tmp;
				continue;
			}
			str_add(ret, tmp);
		}
	};
	auto str_pow = [&str_mul] (int n, int pow) {
		string num = to_string(n);
		string tmp = num;
		string ret = !pow ? "1" : num;
		for (int i = 1; i < pow; i++) {
			str_mul(tmp, num, ret);
			tmp = ret;
		}
		return ret;
	};

	for (int n = 0, res = 0, cnt = 0;; res += cnt, cnt = 0, n++) {
		for (int p = 1; p == str_pow(n + 1, p).length(); p++, cnt++);
		if (!cnt) {
			cout << res << endl;
			break;
		}
	}

	return 0;
}
