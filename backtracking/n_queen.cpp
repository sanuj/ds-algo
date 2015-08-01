#include <iostream>
#include <vector>
using namespace std;

bool is_legal(vector< vector<int> > &board, int x, int y) {
	int n = board.size();
	for(int i=0; i<n; i++) {
		if(board[x][i] == 1 || board[i][y] == 1)
			return false;
		if(x-i >= 0 && y-i >=0)
			if(board[x-i][y-i] == 1) return false;
		if(x+i < n && y+i < n)
			if(board[x+i][y+i] == 1) return false;
		if(x+i < n && y-i >=0)
			if(board[x+i][y-i] == 1) return false;
		if(x-i >= 0 && y+i < n)
			if(board[x-i][y+i] == 1) return false;
	}
	return true;
}

bool solve_n_queen_helper(vector< vector<int> > &board, int num_queens) {
	int n=board.size();
	if(num_queens == n)
		return true;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(is_legal(board, i, j)) {
				board[i][j] = 1;
				if(solve_n_queen_helper(board, num_queens+1) == false)
					board[i][j] = 0;
				else
					return true;
			}
		}
	}
	return false;
}

void solve_n_queen(int n) {
	vector< vector<int> > board;
	for(int i=0; i<n; i++) {
		vector<int> vec(n, 0);
		board.push_back(vec);
	}

	solve_n_queen_helper(board, 0);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	int n=20;
	solve_n_queen(n);
	return 0;
}