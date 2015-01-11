#include <iostream>
using namespace std;

void ss(int* a, int len) {
	for(int i=0; i<len; i++) {
		int min=a[i];
		int ind=i;
		for(int j=i; j<len; j++) {
			if(a[j] < min) {
				min=a[j];
				ind=j;
			}
		}
		int temp=a[i];
		a[i]=min;
		a[ind]=temp;
	}
	for (int i=0; i<len; i++)
		cout << a[i] << ", ";
	cout << endl;
}

int main() {
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int b[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int d[] = {5, 8, 2, 6, 9, 4, 7, 1, 7};
	ss(a, 9);
	ss(b, 9);
	ss(c, 9);
	ss(d, 9);
	return 0;
}