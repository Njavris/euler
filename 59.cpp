#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	vector<char> cipher;
	ifstream ifs("0059_cipher.txt");
	for (string byte; getline(ifs, byte,',');) {
		unsigned b;
		sscanf(byte.c_str(), "%u", &b);
		cipher.push_back((char)b);
	}
	ifs.close();

	auto decypher = [&cipher] (char key[4], string &ret) -> int {
		int kidx = 0, sum = 0;
		for_each(begin(cipher), end(cipher),
				[&ret, &key, &kidx, &sum] (char &c) {
			char b = c ^ key[kidx++];
			ret.push_back(b);
			kidx %= 3;
			sum += b;
		});
		return sum;
	};

	string common[] = {
		"the ", "at ", "there ", "some ", "my ", "of ", "be ", "use ", "her ", "than ",
/*
		"and ", "this ", "an ", "would ", "first ", "a ", "have ", "each ", "make ", "water ",
		"to", "from", "which", "like", "been", "in", "or", "she", "him", "call",
		"is", "one", "do", "into", "who", "you", "had", "how", "time", "oil",
		"that", "by", "their", "has", "its", "it", "word", "if", "look", "now",
		"he", "but", "will", "two", "find", "was", "not", "up", "more", "long",
		"for", "what", "other", "write", "down", "on", "all", "about", "go", "day",
		"are", "were", "out", "see", "did", "as", "we", "many", "number", "get",
		"with", "when", "then", "no", "come", "his", "your", "them", "way", "made",
		"they", "can", "these", "could", "may", "I", "said", "so", "people", "part",
*/
	};

	int best = 0, best_sum;
	char best_key[4];

	for (char a = 'a'; a != 'z'; a++) {
		for (char b = 'a'; b != 'z'; b++) {
			for (char c = 'a'; c != 'z'; c++) {
				char key[] = {a, b, c, '\0'};
				int matched = 0;
				string plain;
				int sum = decypher(key, plain);

				for (auto &w: common) {
					if (plain.find(w) != string::npos)
						matched ++;
				}
				if (matched > best) {
					best = matched;
					best_sum = sum;
					*((unsigned *)best_key) = *((unsigned *)key);
				}
			}
		}
	}

	string plain;
	decypher(best_key, plain);
	cout << "key: " << best_key << endl;
	cout << "plaintext: " << endl <<  plain << endl;

	cout << endl << best_sum << endl;
	return 0;
}
