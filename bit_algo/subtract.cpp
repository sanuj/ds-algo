#include <iostream>
using namespace std;

/**
 * Uses truth table to subtract y from x
 * 	x	y	diff	carry
 * 	0	0	0		0
 * 	0	1	1		1
 * 	1	1	0		0
 * 	1	0	1		0
 * 
 * returns x-y without using arithmetic operators
 */
 
int subtract(int x, int y) {
	while(y != 0) {
		int borrow = ~x&y;
		x = x^y;
		y = borrow << 1;
	}
	return x;
}

int main() {
	cout << subtract(3, 4) << endl;
	cout << subtract(567, 123) << endl;
	cout << subtract(34, 235834) << endl;

	return 0;
}
