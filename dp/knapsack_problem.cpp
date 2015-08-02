#include <iostream>
using namespace std;

int solveKnapsackBU(int val[], int wts[], int n, int W) {
	int table[n+1][W+1];
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=W; j++) {
			if(i == 0 || j == 0)
				table[i][j] = 0;
			else if(j-wts[i-1] < 0)
				table[i][j] = table[i-1][j];
			else
				table[i][j] = max(table[i-1][j], val[i-1]+table[i-1][j-wts[i-1]]);
			// cout << table[i][j] << ", ";
		}
		// cout << endl;
	}
	return table[n][W];
}

int solveKnapsack(int val[], int wts[], int n, int W) {
	if(n == 0 || W < 0)
		return 0;
	else if(W-wts[n-1] < 0)
		return solveKnapsack(val, wts, n-1, W);
	else
		return max(solveKnapsack(val, wts, n-1, W),
			val[n-1]+solveKnapsack(val, wts, n-1, W-wts[n-1]));
}

int main() {
	int values[] = {60, 100, 120, 40, 70, 90};
	int weights[] = {10, 20, 10, 40, 50, 30};
	int n = 6;
	int W = 90;
	// int values[] = {6, 10, 12};
 //    int weights[] = {1, 2, 3};
 //    int W = 5;
 //    int n = sizeof(values)/sizeof(values[0]);
	cout << solveKnapsackBU(values, weights, n, W) << endl;
	return 0;
}