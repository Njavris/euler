#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	const string cards = "23456789TJQKA";
	const string suites = "HSCD";
	int res = 0;

	ifstream ifs("0054_poker.txt");
	for (string ln; getline(ifs, ln);) {
		stringstream ss(ln);
		string s;
		unsigned p[2][5] = { 0 };
//		cout << ln << endl;
		for (int i = 1; ss >> s; i++) {
			unsigned mask = 0;
			int suite = 0;
			for (; (suite < suites.length()) && (suites[suite] != s[1]); suite++);
			for (int i = 0; i < cards.length(); i++) {
				if (s[0] == cards[i]) {
					mask = 1 << i;
					break;
				}
			}
			if (i <= 5) {
				p[0][suite] |= mask;
				p[0][4] |= mask;
			} else {
				p[1][suite] |= mask;
				p[1][4] |= mask;
			}
		}

		unsigned pairs[2] = { 0 }, threes[2] = { 0 }, fours[2] = { 0 };
		int highest[2] = { 0 }, flush[2] = { 0 }, straight[2] = { 0 }, pairs_cnt[2] = { 0 };
		for (int i = cards.length(); i>= 0; i--) {
			int sames[2] = { 0 };
			unsigned m = 1 << i;
			unsigned c1 = p[0][4] & m;
			unsigned c2 = p[1][4] & m;
			if (c1 == c2 && !highest[0] && !highest[1]);
			else if (c1 && !highest[0])
				highest[0] = i + 1;
			else if (c2 && !highest[1])
				highest[1] = i + 1;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 2; k++)
					if (p[k][j] & m)
						sames[k] ++;
			}
			for (int k = 0; k < 2; k++) {
				if (sames[k] == 2) {
					pairs[k] |= m;
					pairs_cnt[k]++;
				}
				if (sames[k] == 3)
					threes[k] |= m;
				if (sames[k] == 4)
					fours[k] |= m;
			}
		}
		for (int k = 0; k < 2; k++) {
			int cnt = 0;
			for (int i = 0; i < 4; cnt += !!p[k][i++]);
			if (cnt == 1)
				flush[k]++;

			for (int i = 0; i < 9; i++) {
				if (p[k][4] == (0x1f << i))
					straight[k] = i + 6;
			}
		}

		if (straight[0] && straight[1] && flush[0] && flush[1]) { // Royal flush/ Straight flush
			if ((straight[0] > straight[1]) ||
					((straight[0] == straight[1]) &&
						(highest[0] > highest[1])))
				res++;
		} else if (straight[0] && flush[0]) {
			res++;
		} else if (straight[1] && flush[1]) {
		} else if (fours[0] > fours[1]) { // Four of a Kind
			res++;
		} else if (fours[1] > fours[0]) {
		} else if ((threes[0] > threes[1]) && pairs[0]) { // Full House
			res++;
		} else if ((threes[1] > threes[0]) && pairs[1]) {
		} else if (flush[0] && flush[1]) { // Flush
			if (highest[0] > highest[1])
				res++;
		} else if (flush[0]) {
			res++;
		} else if (flush[1]) {
		} else if (straight[0] && straight[0] > straight[1]) { // Straight
			res++;
		} else if (straight[1] && straight[0] < straight[1]) {
		} else if (threes[0] && threes[0] > threes[1]) { // Three of a Kind
			res++;
		} else if (threes[1] && threes[0] < threes[1]) {
		} else if (pairs_cnt[0] > pairs_cnt[1]) { // One/Two Pairs
			res++;
		} else if (pairs_cnt[0] < pairs_cnt[1]) {
		} else if (pairs_cnt[0] && pairs_cnt[0] == pairs_cnt[1]) {
			if (pairs[0] > pairs[1])
				res++;
		} else if (highest[0] > highest[1]) { // Highest
				res++;
		}
	};
	ifs.close();

	cout << res << endl;
	return 0;
}
