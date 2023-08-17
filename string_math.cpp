#include "string_math.h"

using namespace std;

void str_add(string &n1, string &n2) {
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
	while (r && idx >= 0) {
		int d = n1[idx] - '0' + r;
		r = d / 10;
		d %= 10;
		n1[idx--] = d + '0';
	}
	if (r && idx < 0) {
		n1.insert(begin(n1), '1');
	}
};

void str_mul(string &n1, string &n2, string &ret) {
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

void str_pow(string &num, int pow, string &ret) {
	string tmp = num;
	ret = !pow ? "1" : num;
	for (int i = 1; i < pow; i++) {
		str_mul(tmp, num, ret);
		tmp = ret;
	}
};
