#include <iostream>
using namespace std;

void merge(int* a, int start, int mid, int end) {
	int l[mid-start+1], r[end-mid];
	for(int i=0; i<mid-start+1; i++)
		l[i]=a[start+i];
	for(int i=0; i<end-mid; i++)
		r[i]=a[mid+1+i];
	int j=0, k=0;
	for(int i=start; i<=end; i++) {
		if(j<mid-start+1 && k<end-mid) {
			if(l[j]>r[k]) a[i]=r[k++];
			else a[i]=l[j++];
		}
		else if(j<mid-start+1)
			a[i]=l[j++];
		else if(k<end-mid)
			a[i]=r[k++];
	}
}

void ms_helper(int* a, int start, int end) {
	if(start<end) {
		ms_helper(a, start, (start+end)/2);
		ms_helper(a, (start+end)/2 + 1, end);
		merge(a, start, (start+end)/2, end);
	}
}

void ms(int*a, int len) {
	ms_helper(a, 0, len-1);
	for (int i=0; i<len; i++)
		cout << a[i] << ", ";
	cout << endl;
}

int main() {
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int b[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int d[] = {5, 8, 2, 6, 9, 4, 7, 1, 7};
	ms(a, 9);
	ms(b, 9);
	ms(c, 9);
	ms(d, 9);
	return 0;
}