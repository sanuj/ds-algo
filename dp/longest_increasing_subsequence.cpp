#include <iostream>
#include <stdio.h>
using namespace std;

int lis_bottom_up(int sequence[], int len) {
	int lis_arr[len];
	for(int i=0; i<len; i++) {
		int max=1;
		for(int j=0; j<i; j++) {
			if(sequence[i] < sequence[j] && lis_arr[j]+1 > max)
				max = lis_arr[j]+1;
		}
	}
	int lis_len=1;
	for(int i=0; i<len; i++) {
		if(lis_len < lis_arr[i])
			lis_len = lis_arr[i];
	}
	return lis_len;
}

int lis_helper(int sequence[], int len, int &max) {
	if(len == 1) {
		return 1;
	}

	int result, local_max = 1;
	for(int i=1; i<len; i++) {
		if(sequence[i-1] < sequence[len-1]) {
			int result = lis_helper(sequence, i, max);
			if(local_max < result+1)
				local_max = result+1;
		}
		// result = lis_helper(sequence, i, max);
		// if(sequence[i-1] < sequence[len-1] && local_max < result+1)
		// 	local_max = result+1;
	}

	if(local_max > max)
		max = local_max;

	return local_max;
}

int lis(int sequence[], int len) {
	int max=1;
	lis_helper(sequence, len, max);
	return max;
}

int main() {
	// int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "N: " << n << endl;
    cout << "Length of LIS is " << lis( arr, n ) << endl;
		cout << "Length of LIS is " << lis( arr, n )  << " Bottom Up" << endl;
	return 0;
}
