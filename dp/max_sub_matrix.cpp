#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Prints the sub-matrix with greatest dimensions
 * Solved by using bottom up approach. Dynamic Programming.
 */
void maxSubMatrix(vector< vector<int> > matrix) {
	int row = matrix.size(), col = matrix[0].size();
	int aux_matrix[row][col]; // auxilary matrix
	int max_dim=0, max_dim_x=0, max_dim_y=0; // variables concerned with maximum dimension sub-matrix
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			if(i == 0 || j == 0)
				aux_matrix[i][j] = matrix[i][j];
			else if(matrix[i][j] == 0)
				aux_matrix[i][j] = 0;
			else
				aux_matrix[i][j] = min(aux_matrix[i-1][j-1], min(aux_matrix[i-1][j], aux_matrix[i][j-1])) + 1;
			if(max_dim < aux_matrix[i][j]) {
				max_dim = aux_matrix[i][j];
				max_dim_x = i;
				max_dim_y = j;
			}
		}
	}
	// Printing the sub-matrix
	for(int i=max_dim_x-max_dim+1; i<=max_dim_x; i++) {
		for(int j=max_dim_y-max_dim+1; j<=max_dim_y; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	vector< vector<int> > matrix = {{0, 1, 1, 0, 0, 1}, 
				                   {1, 1, 0, 1, 1, 0}, 
				                   {0, 1, 1, 1, 1, 0},
				                   {1, 1, 1, 1, 1, 0},
				                   {1, 1, 1, 1, 1, 1},
				                   {1, 1, 1, 1, 1, 1},
				                   {0, 0, 0, 0, 1, 0}};
	maxSubMatrix(matrix);
	return 0;
}