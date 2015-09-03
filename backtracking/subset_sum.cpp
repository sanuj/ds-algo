#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Recursive helper function to print all the subsets
 * @vec sorted input set
 * @subset current subset in making
 * @itr iterator in set
 * @sum sum till now
 * @target_sum sum that has to be achieved
 */
void subsetSumHelper(vector<int> &vec, vector<int> &subset, int itr, int sum, int target_sum) {
  if(sum == target_sum) {
    for(int i=0; i<subset.size(); i++)
      cout << subset[i] << " ";
    cout << endl;
  }
  else if(sum+vec[itr] <= target_sum) {
    for(int i=itr; i<vec.size(); i++) {
      subset.push_back(vec[i]);
      subsetSumHelper(vec, subset, i+1, sum+vec[i], target_sum);
      subset.pop_back();
    }
  }
}

/**
 * Function to find subsets with sum = sum
 * Uses backtracking approach
 * @vec input set
 * @sum target sum for each subset
 */
void subsetSum(vector<int> &vec, int sum) {
  vector<int> subset;
  sort(vec.begin(), vec.end());
  if(vec[0] < sum) {
    int total_sum = 0;
    for(int i=0; i<vec.size(); i++)
      total_sum += vec[i];
    if(total_sum >= sum)
      subsetSumHelper(vec, subset, 0, 0, sum);
  }
}

int main() {
  // A set of numbers stored in std::vector
  vector<int> vec = {64, 15, 22, 1, 51, 14, 26, 3, 2, 32, 9, 16, 40, 8};
  subsetSum(vec, 134);
  return 0;
}
