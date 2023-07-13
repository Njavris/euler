#include <iostream>

using namespace std;

int main() {
	constexpr int limit = 1000;
	string f1 = "1", f2 = "1";
	int r;

	auto add = [] (string in1, string in2) -> string {
		string out;
		int c = 0;
		int len = max(in1.size(), in2.size());
		for (int i = 0; i < len; i++) {
			int a1 = (i < in1.size()) ? in1[i] - '0' : 0;
			int a2 = (i < in2.size()) ? in2[i] - '0' : 0;
			int v = a1 + a2 + c;
			c = v / 10;
			out.push_back((v % 10) + '0');
		}
		if (c)
			out.push_back(c + '0');
		return out;
	};

	for(r = 2; f1.size() < limit; r++) {
		string c = add(f1, f2);
		f2 = f1;
		f1 = c;
	}
	cout << r << endl;

	return 0;
}
