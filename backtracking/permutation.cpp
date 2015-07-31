#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Helper function to permute the string str.
 * @str string to permute
 * @perm current permutation under construction
 * @vec vector to save finished permutations in
 */
void permutation_helper(string &str, string &perm, vector<string> &vec) {
	if(str.size() == 0)
		vec.push_back(perm);
	else {
		for(int i=0; i < str.size(); i++) {
			perm.append(str, i, 1);
			string erase_char = "";
			erase_char.append(str, i, 1);
			str.erase(i, 1);
			permutation_helper(str, perm, vec);
			str.insert(i, erase_char);
			perm.pop_back();
		}
	}
}

/**
 * Returns a std::vector of all permutations of the argument string.
 */
vector<string> permutation(string &str) {
	vector<string> vec;
	string empty_str = "";
	permutation_helper(str, empty_str, vec);
	return vec;
}

int main() {
	// Doesn't handle repetitive letter.
	// string str = "ffff";
	// Works well for unique letters
	string str  = "abcdefgh";
	vector<string> perm = permutation(str);
	for(int i=0; i<perm.size(); i++)
		cout << perm[i] << endl;
	return 0;
}