#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Kadane's Algorithm finds maximum sum of contiguous subarray
 * @arr input array
 * @begin saves begining index of subarray with maximum sum (pass by reference)
 * @end saves ending index of subarray with maximum sum (pass by reference)
 */
int kadane(vector<int> &arr, int &begin, int &end) {
  int max_end = arr[0];
  int max_end_here = 0;
  int start = 0;
  for(int i=0; i<arr.size(); i++) {
    if(max_end_here < 0) {
      start = i;
      max_end_here = 0;
    }
    max_end_here += arr[i];
    if(max_end_here > max_end) {
      max_end = max_end_here;
      begin = start;
      end = i;
    }
  }
  return max_end;
}

/**
 * Prints the indices and sum of submatrix having maximum sum
 * @m input matrix
 */
void maxSumSubMatrix(vector< vector<int> > &m) {
  int row = m.size();
  if(row == 0) return;
  int col = m[0].size();
  int max_sum = INT_MIN;
  int begin[] = {0, 0};
  int end[] = {0, 0};
  for(int i=0; i<col; i++) {
    vector<int> sum_row(row, 0);
    for(int j=i; j<col; j++) {
      
      for(int k=0; k<row; k++)
        sum_row[k] += m[k][j];

      int row_begin=0, row_end=0;
      int sum = kadane(sum_row, row_begin, row_end);
      if(sum > max_sum) {
        max_sum = sum;
        begin[0] = row_begin;
        begin[1] = i;
        end[0] = row_end;
        end[1] = j;
      }
    }
  }

  cout << "Maximum sum is " << max_sum << endl;
  cout << "Submatrix starts from (" << begin[0] << ", " << begin[1] <<
    ") and ends at (" << end[0] << ", " << end[1] << ")" << endl;
}

int main() {
  vector< vector<int> > matrix = {{1, 2, 3, -1},
                                  {-4, -4, -4, -3},
                                  {4, 5, 6, -5},
                                  {7, 8, 9, 4},
                                  {-1, 3, -1, 4}};
  maxSumSubMatrix(matrix);

  // Code to print matrix
  // for(int i=0; i<matrix.size(); i++) {
  //   for(int j=0; j<matrix[i].size(); j++) {
  //     cout << matrix[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}
