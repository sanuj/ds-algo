#include <iostream>
using namespace std;

/**
 * Uses bitwise XOR
 */
bool oppositeSign(int a, int b) {
	return ((a^b) < 0);
}

int main() {
	int a = 25, b = -30;
	cout << oppositeSign(a, b) << endl;
	a = -25, b = -30;
	cout << oppositeSign(a, b) << endl;
	a = -25, b = 30;
	cout << oppositeSign(a, b) << endl;
	return 0;
}