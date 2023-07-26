#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	int res = 0;
	vector<string> words;
	vector<int> triangle;
	ifstream ifs("0042_words.txt");
	for (string wd; getline(ifs, wd, ','); words.push_back(wd.substr(1, wd.size() - 2)));
	ifs.close();

	for_each(begin(words), end(words), [&triangle, &res] (string &wd) {
		auto gen_triangle_nums = [&triangle] (int limit) -> void{
			int i = triangle.size();
			for (i++;; i++) {
				int tn = (i * i + i) / 2;
				if (tn > limit)
					break;
				triangle.push_back(tn);
			}
		};
		int sum = 0;
		for_each(begin(wd), end(wd), [&sum] (char c) -> void {
			sum += c - 'A' + 1;
		});
		gen_triangle_nums(sum);
		if (find(begin(triangle), end(triangle), sum) != end(triangle))
			res ++;
	});
	cout << res << endl;
	return 0;
}
