#include <iostream>
#include <string>

#include "string_math.h"

using namespace std;

int main() {
	constexpr int limit = 100;

	auto fr = [] (int n) {
		return to_string(n == 1 ? 2 : !(n % 3) ? 2 * n / 3 : 1);
	};
	string num = fr(limit);
	string den = to_string(1);
	for (int i = limit - 1; i > 0; i --) {
		string tmp, a = fr(i);
		str_mul(num, a, tmp);
		str_add(tmp, den);
		den = num;
		num = tmp;
	}
	int res = 0;
	for_each(begin(num), end(num), [&res] (const char &c) { res += c - '0'; });
	cout << res << endl;
	return 0;
}
