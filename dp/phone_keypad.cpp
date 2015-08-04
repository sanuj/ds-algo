#include <iostream>
using namespace std;

char keypad[][3] = {{'1', '2', '3'},
				   {'4', '5', '6'},
				   {'7', '8', '9'},
				   {'*', '0', '#'}};

/**
 * Dynamic Pragramming solution
 */
int countHelperDP(int n) {
	int aux_mat[4][3];
	for(int i=0; i<4; i++) {
		for(int j=0; j<3; j++) {
			if(keypad[i][j] != '*' && keypad[i][j] != '#')
				aux_mat[i][j] = 1;
			else
				aux_mat[i][j] = 0;
		}
	}
	int row[] = {0, -1, 0, 1, 0};
	int col[] = {0, 0, -1, 0, 1};
	for(int i=1; i<n; i++) {
		int temp_aux_mat[4][3];
		for(int i=0; i<4; i++) {
			for(int j=0; j<3; j++) {
				if(keypad[i][j] != '*' && keypad[i][j] != '#') {
					if(i == 0 && j == 0) 
						temp_aux_mat[i][j] = aux_mat[i][j] + aux_mat[i+1][j] + aux_mat[i][j+1];
					else if(i == 0 && j == 2)
						temp_aux_mat[i][j] = aux_mat[i][j] + aux_mat[i+1][j] + aux_mat[i][j-1];
					else if(i == 0)
						temp_aux_mat[i][j] = aux_mat[i][j] + aux_mat[i+1][j] + aux_mat[i][j+1] + aux_mat[i][j-1];
					else if(j == 0)
						temp_aux_mat[i][j] = aux_mat[i][j] + aux_mat[i+1][j] + aux_mat[i][j+1] + aux_mat[i-1][j];
					else if(j == 2)
						temp_aux_mat[i][j] = aux_mat[i][j] + aux_mat[i+1][j] + aux_mat[i][j-1] + aux_mat[i-1][j];
					else if(i == 3 && j == 1)
						temp_aux_mat[i][j] = aux_mat[i][j] + aux_mat[i-1][j];
					else
						temp_aux_mat[i][j] = aux_mat[i][j] + aux_mat[i+1][j] + aux_mat[i][j+1] + aux_mat[i-1][j] + aux_mat[i][j-1];
				}
				else
					temp_aux_mat[i][j] = 0;
			}
		}
		for(int i=0; i<4; i++)
			for(int j=0; j<3; j++)
				aux_mat[i][j] = temp_aux_mat[i][j];
	}
	int counter = 0;
	for(int i=0; i<4; i++)
		for(int j=0; j<3; j++)
			counter += aux_mat[i][j];

	return counter;
}

/**
 * Recursively solves in a top down approach.
 */
int countHelper(int i, int j, int n) {
	if(n == 0) {
		// cout << i << ", " << j << " returned 0" << endl;
		return 0;
	}
	if(n == 1 && keypad[i][j] != '*' && keypad[i][j] != '#') {
		// cout << i << ", " << j << " returned 1" << endl;
		return 1;
	}
	else {
		int count = 0;
		int row[] = {0, -1, 0, 1, 0};
		int col[] = {0, 0, -1, 0, 1};
		if(keypad[i][j] != '*' && keypad[i][j] != '#') {
			for(int p=0; p<5; p++) {
				if(i+row[p] >= 0 && i+row[p] < 4 && j+col[p] >=0 && j+col[p] < 3) {
					count += countHelper(i+row[p], j+col[p], n-1);
				}
			}
		}
		// cout << i << ", " << j << " returned " << count << endl;
		return count;
	}
}

int count(int n) {
	if(n == 0) return 0;

	int counter = 0;
	for(int i=0; i<4; i++)
		for(int j=0; j<3; j++)
			counter += countHelper(i, j, n);
	
	return counter;
}

int main() {
	int n=4;
	// cout << count(n) << endl;
	cout << countHelperDP(n) << endl;
	return 0;
}