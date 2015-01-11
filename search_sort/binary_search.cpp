#include <iostream>
using namespace std;

int bs_helper(int* a, int start, int end, int q) {
	if (start <= end) {
		int mid=(start+end)/2;
		if(a[mid] == q) return mid;
		else if(a[mid] > q) return bs_helper(a, start, mid-1, q);
		else if(a[mid] < q) return bs_helper(a, mid+1, end, q);
	}
	return -1;
}

int bs(int* a, int len, int q) {
	int start = 0;
	int end = len - 1;
	return bs_helper(a, start, end, q);
}

int main() {
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	cout << bs(a, 9, 0) << endl;
	cout << bs(a, 9, 1) << endl;
	cout << bs(a, 9, 2) << endl;
	cout << bs(a, 9, 3) << endl;
	cout << bs(a, 9, 4) << endl;
	cout << bs(a, 9, 5) << endl;
	cout << bs(a, 9, 6) << endl;
	cout << bs(a, 9, 7) << endl;
	cout << bs(a, 9, 8) << endl;
	cout << bs(a, 9, -1) << endl;
	cout << bs(a, 9, 9) << endl;
	return 0;
}