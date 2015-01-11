#include <iostream>
using namespace std;

void is(int* a, int len) {
	for(int i=1; i<len; i++) {
		for(int j=0; j<i; j++) {
			if(a[j] > a[i]) {
				for (int k=i; k>j; k--) {
					int temp=a[k];
					a[k]=a[k-1];
					a[k-1]=temp;
				}
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
	is(a, 9);
	is(b, 9);
	is(c, 9);
	is(d, 9);
	return 0;
}