#include <iostream>
#include <cmath>
using namespace std;

bool isMultipleOfThree(int num) {
	num = abs(num);
	if(num == 0) return true;
	else if(num == 1) return false;
	else {
		int odd=0, even=0;
		while(num != 0) {
			if(num & 1 == 1)
				odd++;
			num = num >> 1;
			if(num & 1 == 1)
				even++;
			num = num >> 1;
		}
		// cout << "Odd: " << odd << ", " << "Even: " << even << endl;
		return isMultipleOfThree(odd-even);
	}
}

int main() {
	cout << isMultipleOfThree(27) << endl;
	cout << isMultipleOfThree(234987) << endl;
	return 0;
}