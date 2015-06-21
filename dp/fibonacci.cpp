#include <iostream>
using namespace std;

int fib_memoiz_helper(int n, int *memo) {
	if(memo[n] != -1) return memo[n];
	memo[n] = fib_memoiz_helper(n-1, memo) + fib_memoiz_helper(n-2, memo);
	return memo[n];
}

int fib_memoiz(int n) {
	int memo[n];
	for(int i=0; i<=n; i++)
		memo[i] = -1;
	memo[0] = 0;
	memo[1] = 1;
	return fib_memoiz_helper(n, memo);
}

int fib_bottom_up(int n) {
	int memo[n];
	memo[0] = 0;
	memo[1] = 1;
	cout << memo[0] << ", " << memo[1] << ", ";
	for(int i=2; i<=n; i++) {
		memo[i] = memo[i-1] + memo[i-2];
		cout << memo[i] << ", ";
	}
	cout << endl;
}

int main() {
	int n = 10;
	// Memoization Approach
	// for(int i=0; i<n; i++)
	// 	cout << fib_memoiz(i) << ", ";
	// cout << endl;

	// Bottom Up Approach
	fib_bottom_up(n);
	return 0;
}