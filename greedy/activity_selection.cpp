#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct representing an activity
struct Act {
	int begin;
	int end;
};

// Used to sort a vector of activities
bool compare(const Act &a, const Act &b) {
  return a.end < b.end;
}

/**
 * Sorts the input vector of activities by the end time.
 * Uses greedy approach
 */
void activitySelection(vector<Act> a) {
	sort(a.begin(), a.end(), compare);
	vector<Act> opt_a;
	for(int i=0; i<a.size(); i++) {
		if(i == 0)
			opt_a.push_back(a[i]);
		else if(a[i].begin >= opt_a[opt_a.size()-1].end)
			opt_a.push_back(a[i]);
	}
	for(int i=0; i<opt_a.size(); i++)
		cout << opt_a[i].begin << ", " << opt_a[i].end << endl;
}

int main() {
	vector<Act> a = {{1, 2}, {3, 4}, {1, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}, {11, 13}};
	activitySelection(a);
	return 0;
}