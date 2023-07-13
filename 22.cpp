#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<string> names;
	ifstream ifs("0022_names.txt");
	for (string nm; getline(ifs, nm,',');names.push_back(nm.substr(1,nm.size() - 2)));
	sort(begin(names), end(names));
	int r = 0;
	for_each(begin(names), end(names), [i = 1, &r] (auto n) mutable {
		int s = 0;
		for_each(begin(n), end(n), [&s] (auto e) { s += e - 'A' + 1; });
		r += s * i++;
	});
	cout << r << endl;
	return 0;
}
