#include <iostream>
#include <vector>
using namespace std;

int change_combos_BU(int *coins, int num_coins, int val) {
	if(num_coins == 0 && val == 0)
		return 1;
	else if(num_coins == 0)
		return 0;
	int table[val+1][num_coins];
	for(int i=0; i<num_coins; i++)
		table[0][i] = 1;
	for(int i=1; i<val+1; i++) {
		for(int j=0; j<num_coins; j++) {
			int inc_coin=0, ex_coin=0;
			// Including the current coin
			if(i-coins[j] >= 0)
				inc_coin = table[i-coins[j]][j];
			// Excluding the current coin
			if(j >= 1)
				ex_coin = table[i][j-1];
			table[i][j] = inc_coin + ex_coin; 
		}
	}
	// for(int i=0; i<val+1; i++) {
	// 	for(int j=0; j<num_coins; j++) {
	// 		cout << table[i][j] << ", "; 
	// 	}
	// 	cout << endl;
	// }
	return table[val][num_coins-1];
	// Incomplete for now.
}

int change_combos_memo_helper(int *coins, int num_coins, int val, vector< vector<int> > &dict) {
	if(val == 0)
		return 1;
	if(val > 0 && num_coins > 0) {
		if(dict[num_coins-1][val-1] != -1)
			return dict[num_coins-1][val-1];
		else {
			dict[num_coins-1][val-1] = change_combos_memo_helper(coins, num_coins-1, val, dict)
				+ change_combos_memo_helper(coins, num_coins, val-coins[num_coins-1], dict);
		}
		return dict[num_coins-1][val-1];
	}
	else
		return 0;
}

int change_combos_memo(int *coins, int num_coins, int val) {
	vector<vector<int> > dict( num_coins, vector<int>(val, -1));
	return change_combos_memo_helper(coins, num_coins, val, dict);
}

int change_combos_naive(int *coins, int num_coins, int val) {
	if(val == 0)
		return 1;
	if(val > 0 && num_coins > 0) {
		return change_combos_naive(coins, num_coins-1, val) + change_combos_naive(coins, num_coins, val-coins[num_coins-1]);
	}
	else
		return 0;
}

int main() {
	int num_coins = 4;
	int coins[] = {1, 2, 3, 4};
	int val = 6;
	// int num_coins = 2;
	// int coins[] = {1, 2};
	// int val = 3;
	// int num_coins = 10;
	// int coins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int val = 200;
	// int num_coins = 0;
	// int coins[] = {};
	// int val = 0;
	// cout << change_combos_naive(coins, num_coins, val) << endl;
	// cout << change_combos_memo(coins, num_coins, val) << endl;
	cout << change_combos_BU(coins, num_coins, val) << endl;
	return 0;
}