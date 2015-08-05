#include <iostream>
#include <vector>
using namespace std;

/**
 * Divide and conquer approach. Exactly like merge sort.
 */
int countInversionsHelper(vector<int> &arr, int begin, int end) {
	if(begin < end) {
		int mid = (begin+end)/2;
		// Divide
		int l_inv = countInversionsHelper(arr, begin, mid);
		int r_inv = countInversionsHelper(arr, mid+1, end);

		// Conquer. Merging steps.
		int i=begin, j=mid+1, inv=0;
		vector<int> temp;
		while(i <= mid && j <= end) {
			if(arr[i] <= arr[j]) {
				temp.push_back(arr[i++]);
			}
			else {
				temp.push_back(arr[j++]);
				inv += mid-i+1;
			}
		}
		while(i <= mid) temp.push_back(arr[i++]);
		while(j <= end) temp.push_back(arr[j++]);
		int l=0;
		for(int k=begin; k<=end; k++)
			arr[k] = temp[l++];
		return inv+l_inv+r_inv;
	}
	else
		return 0;
}

int countInversionsDC(vector<int> &arr) {
	return countInversionsHelper(arr, 0, arr.size()-1);
}

/**
 * Naive approach
 */
int countInversionsNaive(vector<int> &arr) {
	int inv=0;
	for(int i=0; i<arr.size(); i++) {
		for(int j=i+1; j<arr.size(); j++) {
			if(arr[i] > arr[j])
				inv++;
		}
	}
	return inv;
}

int main() {
	// vector<int> arr = {1, 20, 6, 4, 5};
	vector<int> arr = {1, 5, 16, 20, 6, 19, 20, 4, 5};
	// cout << "Number of inversions: " << countInversionsNaive(arr) << endl;
	cout << "Number of inversions: " << countInversionsDC(arr) << endl;
	return 0;
}