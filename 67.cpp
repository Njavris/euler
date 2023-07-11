#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

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
	vector<vector<int>> triangle;

	ifstream fl("0067_triangle.txt");
	string ln;
	while (getline(fl, ln)) {
		stringstream ss = stringstream(ln);
		vector<int> row;
		int elem;
		while (ss >> elem)
			row.push_back(elem);
		triangle.push_back(row);
	}

	for (int i = 1; i < triangle.size(); i++) {
		triangle[i][0] += triangle[i - 1][0] ;
		triangle[i][i] += triangle[i - 1][i - 1];
		for (int j = 1; j < triangle[i].size() - 1; j++) {
			int sum1 = triangle[i][j] + triangle[i - 1][j - 1];
			int sum2 = triangle[i][j] + triangle[i - 1][j];
			triangle[i][j] = max(sum1, sum2);
		}
	}

	int max = 0;
	for (auto &e: triangle[triangle.size() - 1]) {
		if (e > max)
			max = e;
	}
	cout << max << endl;
	return 0;
}
