#include <iostream>
#include <map>
#include <math.h>
using namespace std;

map<int, int> findPrimeFactors(int n) {
	map<int, int> factors;
	int num_twos=0;

	while(n%2 == 0) {
		num_twos++;
		n /=2;
	}
 	if(num_twos > 0)
		factors[2] = num_twos;

	for(int i=3; i<=sqrt(n); i+=2) {
		int num_factor = 0;
		while(n%i == 0) {
			num_factor++;
			n /= i;
		}
		if(num_factor > 0)
			factors[i] = num_factor;
	}

	if(n > 1)
		factors[n] = 1;
	
	return factors;
}

void printPrimeFactors(int num) {
	map<int, int> factors = findPrimeFactors(num);
	map<int, int>::iterator iter;

	cout << "Prime Factors of " << num << " are: " << endl;
	for(iter = factors.begin(); iter != factors.end(); iter++) {
		cout << iter->first << "=> " << iter->second << endl;
	}
}

int main() {
	printPrimeFactors(1666350);
	printPrimeFactors(982357938);
	printPrimeFactors(2230);
	printPrimeFactors(529);
	return 0;
}