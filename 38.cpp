#include <iostream>

using namespace std;

int main() {
	int result = 0;

	for (int i = 1; i < 100000; i++) {
		auto isPandigital = [] (string &s) -> bool {
			if (s.length() != 9)
				return false;
			for (int i = 1; i <= 9; i++) {
				if (s.find('0' + i) == string::npos)
					return false;
			}
			return true;
		};
		string str, prev;
		int n = 1;
		while (str.size() < 9) {
			string curr = to_string(i * n);
			prev = str;
			str += curr;
			n++;
		}
		if (isPandigital(str)) {
			int val = stoi(str);
			if (val > result)
				result = val;
		}
	}
	cout << result << endl;

	return 0;
}
