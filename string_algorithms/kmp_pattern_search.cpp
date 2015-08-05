#include <iostream>
#include <string>
using namespace std;

void makeAuxArr(string &pat, int *aux_arr) {
	int i=0, j=0;
	aux_arr[i++] = 0;
	while(i<pat.size()) {
		if(pat[i] == pat[j]) {
			j++;
			aux_arr[i] = j;
			i++;
		}
		else if(j!=0) {
			j = aux_arr[j-1];
		}
		else {
			aux_arr[i] = 0;
			i++;
		}
	}
}

int KMPPatternSearch(string &txt, string &pat) {
	int aux_arr[pat.size()];
	makeAuxArr(pat, aux_arr);

	int i=0, j=0;
	while(i<txt.size()) {
		if(txt[i] == pat[j]) {
			i++; j++;
			if(j == pat.size()) return i-j;
		}
		else if(j!=0) {
			j = aux_arr[j-1];
		}
		else {
			i++;
		}
	}

	// for(int i=0; i<pat.size(); i++)
	// 	cout << aux_arr[i] << ", ";
	// cout << endl;
	return -1;
}

int main() {
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	// string txt = "AAAAAAAAAAAAAAAAAB";
	// string pat = "AAAAB";
	// string txt = "ABABABCABABABCABABABC";
	// string pat =  "ABABAC";
	cout << KMPPatternSearch(txt, pat) << endl;
	return 0;
}