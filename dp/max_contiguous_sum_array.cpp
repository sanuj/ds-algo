#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Helper function for top down recursive method.
 * @vec input vector
 * @aux_vec auxiliary vector
 * @i index
 */
int maxContiguousSumTopDownHelper(vector<int> &vec, vector<int> &aux_vec, int i) {
  if(i == 0)
    aux_vec[i] = vec[i];
  else
    aux_vec[i] = max(vec[i],
      maxContiguousSumTopDownHelper(vec, aux_vec, i-1)+vec[i]);
  return aux_vec[i];
}

/**
 * Dynamic Programming solution. Top down recursive approach.
 * Returns maximum contiguous subarray sum in the input array
 * @vec input vector
 */
int maxContiguousSumTopDown(vector<int> &vec) {
  vector<int> aux_vec(vec.size(), INT_MIN);
  maxContiguousSumTopDownHelper(vec, aux_vec, vec.size()-1);
  int max=INT_MIN;
  for(int i=0; i<aux_vec.size(); i++)
    max = (aux_vec[i] > max)?aux_vec[i]:max;
  return max;
}

/**
 * Dynamic Programming solution. Bottom up tabulation approach.
 * Returns maximum contiguous subarray sum in the input array
 * @vec input vector
 */
int maxContiguousSumBottomUp(vector<int> &vec) {
  vector<int> aux_vec(vec.size(), 0);
  aux_vec[0] = vec[0];
  // cout << aux_vec[0] << endl;
  int max = aux_vec[0];
  for(int i=1; i<aux_vec.size(); i++) {
    aux_vec[i] = vec[i];
    if(aux_vec[i-1] + vec[i] > aux_vec[i])
      aux_vec[i] = aux_vec[i-1] + vec[i];
    // cout << aux_vec[i] << endl;
    if(max < aux_vec[i])
      max = aux_vec[i];
  }
  return max;
}

int main() {
  // vector<int> vec = {1, 3, -2, 4, -6, 8, -1, 5, -7, 9, -2, -1};
  vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3};
  // cout << maxContiguousSumTopDown(vec) << endl;
  cout << maxContiguousSumBottomUp(vec) << endl;
  return 0;
}
