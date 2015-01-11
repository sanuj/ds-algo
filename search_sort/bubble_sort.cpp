#include <iostream>
using namespace std;

void bs(int* a, int len) {
	for(int i=0; i<len; i++) {
		for(int j=0; j<len-i-1; j++) {
			if(a[j] > a[j+1]) {
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	for(int i=0; i<len; i++)
		cout << a[i] << ", ";
	cout << endl;
}

int main() {
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int b[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int d[] = {5, 8, 2, 6, 9, 4, 7, 1, 7};
	bs(a, 9);
	bs(b, 9);
	bs(c, 9);
	bs(d, 9);
	return 0;
}