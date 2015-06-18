#include <iostream>
#include <vector>
using namespace std;

// Finds primes till n and saves them in the primes vector
void getPrimesTillN(int n, vector<int> &primes) {
	int arr[n];

	// Setting all values to 0
	for(int i=0; i<n; i++)
		arr[i] = 0;

	for(int i=1; i<n; i++) {
		if(arr[i] == 0) {
			primes.push_back(i+1);
			int j=2;
			
			// Marking all the multiples of (i+1) as 1
			while(j*(i+1)<=n) {
				arr[j*(i+1)-1] = 1;
				j++;
			}
		}
	}
}

// Function to print the vector of primes
void printPrimesTillN(int n) {
	vector<int> primes;
	getPrimesTillN(n, primes);
	cout << "List of primes till " << n << ": " << endl;
	if(!primes.empty()) {
		for(int i=0; i<primes.size()-1; i++)
			cout << primes[i] << ", ";
		cout << primes[primes.size()-1];
	}
	cout << endl;
}

int main() {
	for(int i=0; i<150; i++)
		printPrimesTillN(i);
	return 0;
}