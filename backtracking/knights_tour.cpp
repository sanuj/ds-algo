#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_legal(vector< vector<int> > &board, int x, int y) {
	if(x >= 0 && y >= 0 && y < board[0].size() && x < board.size() && board[x][y] == -1)
		return true;
	return false;
}

void knights_tour_helper(vector< vector<int> > &board, int x, int y, int count) {
	if(count < board[0].size()*board.size()) {
		board[x][y] = count;
		for(int i=-2; i<=2; i++) {
			for(int j=-2; j<=2; j++) {
				if(i != 0 && j != 0 && abs(i)!=abs(j) && is_legal(board, x+i, y+j)) {
					knights_tour_helper(board, x+i, y+j, count+1);
				}
			}
		}
	}
}

void knights_tour(int row, int col, int x, int y) {
	vector< vector<int> > board;
	for(int i=0; i<row; i++) {
		vector<int> vec(col, -1);
		board.push_back(vec);
	}

	// for(int i=0; i<row; i++) {
	// 	for(int j=0; j<col; j++) {
	// 		cout << board[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }

	knights_tour_helper(board, x, y, 0);

	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	knights_tour(8, 8, 0, 0);
	return 0;
}