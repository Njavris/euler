#include <iostream>
#include <string>

using namespace std;

int main() {
	constexpr int target = 1000000;
	string els = "0123456789";

	auto perm = [] (string els, int p) -> string {
		string r;
		auto fact = [] (int n) -> int {
			int r = 1;
			for (int i = 1; i <= n; r *= i++);
			return r;
		};

		p--;

		for (int i = els.size(); i > 0; i--) {
			int f = fact(i - 1);
			int c = p / f;
			p %= f;
			r.push_back(els[c]);
			els.erase(c, 1);
		}
		return r;
	};

	cout << perm(els, target) << endl;

	return 0;
}
