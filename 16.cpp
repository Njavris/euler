#include <iostream>
#include <string>

using namespace std;

string powerUp(string in) {
	string out;
	int c = 0;
	for (int i = 0; i < in.size(); i++) {
		int v = (in[i] - '0') * 2 + c;
		c = v / 10;
		out.push_back((v % 10) + '0');
	}
	if (c)
		out.push_back(c + '0');
	return out;
}

int main() {
	int r = 0, limit = 1000;
	string s = "1";
	for (int i = 0; i < limit; i++) {
		s = powerUp(s);
//		cout << s << endl;
	}

	for (int i = 0; i < s.size(); i++)
		r += s[i] - '0';
	cout << r << endl;

	return 0;
}
