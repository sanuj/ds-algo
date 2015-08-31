#include <iostream>
using namespace std;

/**
 * Uses truth table to compute sum
 * 	x	y	sum	   carry
 * 	0	0	0		0
 * 	0	1	1		0
 * 	1	1	0		1
 * 	1	0	1		0
 * 
 * returns x+y without using arithmetic operators
 */
 
int add(int x, int y) {
	while(y) {
		int carry = x&y;
		x = x^y;
		y = carry << 1;
	}
	return x;
}

int main() {
	cout << add(3, 4) << endl;
	cout << add(567, 123) << endl;
	return 0;
}
