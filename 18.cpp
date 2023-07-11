#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
i(parL,par2R):
n
0	75(-)
1	0(0) 1(0)
2	0(0) 1(0,1) 2(1)
3	0(0) 1(0,1) 2(1,2) 3(2)
4	0(0) 1(0,1) 2(1,2) 3(2,3) 4(3)
5	0(0) 1(0,1) 2(1,2) 3(2,3) 4(3,4) 5(4)

Parents:
	i - 1, i where i >= 0 && i <= (n - 1) and n > 0
Children:
	i, i + 1 where i >= 0 && i <= n



*/

int main() {
	vector<string> input = {
		"75",
		"95 64",
		"17 47 82",
		"18 35 87 10",
		"20 04 82 47 65",
		"19 01 23 75 03 34",
		"88 02 77 73 07 63 67",
		"99 65 04 28 06 16 70 92",
		"41 41 26 56 83 40 80 70 33",
		"41 48 72 33 47 32 37 16 94 29",
		"53 71 44 65 25 43 91 52 97 51 14",
		"70 11 33 28 77 73 17 78 39 68 17 57",
		"91 71 52 38 17 14 91 43 58 50 27 29 48",
		"63 66 04 68 89 53 67 30 73 16 69 87 40 31",
		"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23",
	};
	vector<vector<int>> triangle;

	for (auto &s: input) {
		stringstream ss = stringstream(s);
		vector<int> row;
		int elem;
		while (ss >> elem)
			row.push_back(elem);
		triangle.push_back(row);
	}
//	for (auto &r: triangle) {
//		for (auto &e: r)
//			cout << e << " ";
//		cout << endl;
//	}
//	cout << endl;

	for (int i = 1; i < triangle.size(); i++) {
		triangle[i][0] += triangle[i - 1][0] ;
		triangle[i][i] += triangle[i - 1][i - 1];
		for (int j = 1; j < triangle[i].size() - 1; j++) {
			int sum1 = triangle[i][j] + triangle[i - 1][j - 1];
			int sum2 = triangle[i][j] + triangle[i - 1][j];
			triangle[i][j] = max(sum1, sum2);
		}
	}

//	for (auto &r: triangle) {
//		for (auto &e: r)
//			cout << e << " ";
//		cout << endl;
//	}

	int max = 0;
	for (auto &e: triangle[triangle.size() - 1]) {
		if (e > max)
			max = e;
	}
	cout << max << endl;
	return 0;
}
