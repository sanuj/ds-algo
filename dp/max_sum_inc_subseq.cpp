#include <iostream>
#include <vector>
using namespace std;

/**
 * Recursive Helper function. Implementation based on DP(Memoization/Top-Down).
 * Similar to Longest Increasing Sequence Problem
 * @arr input array
 * @max_arr auxiliary array which stores maximum sum values
 */
int maxSumIncSubseqHelper(vector<int> &arr, int n, vector<int> &max_arr) {
	if(n == 0) return arr[0];
	else {
		int sum=0;
		for(int i=n-1; i>=0; i--) {
			if(max_arr[i] == -1)
				max_arr[i] = maxSumIncSubseqHelper(arr, i, max_arr);
			if(arr[i] < arr[n]) {
				if(arr[n]+max_arr[i] > sum)
					sum = arr[n]+max_arr[i];
			}
		}
		return sum;
	}
}

/**
 * Wrapper function to calculate Maximum sum of increasing sequence from input array
 * @arr input array
 */
int maxSumIncSubseq(vector<int> arr) {
	vector<int> max_arr(arr.size(), -1);
	max_arr[arr.size()-1] = maxSumIncSubseqHelper(arr, arr.size()-1, max_arr);
	int max=0;
	for(int i=0; i<max_arr.size(); i++)
		if(max_arr[i] > max) max = max_arr[i];
	return max;
}

int main() {
	vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
	// vector<int> arr = {1, 6, 2, 3};
	// vector<int> arr = {10, 5, 4, 3};
	cout << maxSumIncSubseq(arr) << endl;
	return 0;
}