#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Job{
	string id; // id
	int dl; // deadline
	int pro; // profit
};


/**
 * Helper function for sequenceJobsNaive function.
 * @jobs vector of all the available jobs
 * @status vector respresenting statuses of all the jobs
 * @t variable representing current time
 */
int sequenceJobsHelper(vector<Job> &jobs, vector<int> &status, int t) {
	int profit = 0;
	for(int i=0; i<jobs.size(); i++) {
		if(status[i] == 0 && jobs[i].dl >= t) {
			status[i] = 1;
			int temp_pro = sequenceJobsHelper(jobs, status, t+1);
			profit = max(profit, jobs[i].pro + sequenceJobsHelper(jobs, status, t+1));
			status[i] = 0;
		}
	}
	return profit;
}

/**
 * Brute Force approach. Return maximum total profit and not the sequence of jobs.
 * @jobs vector of all the available jobs
 */
void sequenceJobsNaive(vector<Job> &jobs) {
	vector<int> status(jobs.size(), 0);
	cout << sequenceJobsHelper(jobs, status, 1) << endl;
}

/**
 * Compares struct Job by profit values for std::sort
 * Sorts in descending order.
 */
bool compare(const Job& first, const Job& second) {
  return first.pro > second.pro;

}

/**
 * Greedy approach. Sorts the jobs vector in descending order,
 * then outputs all the jobs meeting their respective deadlines.
 */
void sequenceJobsGreedy(vector<Job> &jobs) {
	vector<int> status(jobs.size(), 0);
	sort(jobs.begin(), jobs.end(), compare);
	for(int i=0; i<jobs.size(); i++) {
		for(int j=min(jobs[i].dl, (int)jobs.size())-1; j>=0; j--) {
			if(status[j] == 0) {
				status[j] = 1;
				cout << jobs[i].id << ", ";
				break;
			}
		}
	}
	cout << endl;
}

int main() {
	vector<Job> jobs = {{"a", 2, 100},
						{"b", 1, 19},
						{"c", 2, 27},
						{"d", 1, 25},
						{"e", 3, 15}};
	// vector<Job> jobs = {{"a", 4, 20},
	// 					{"b", 1, 10},
	// 					{"c", 1, 40},
	// 					{"d", 1, 30}};
	// sequenceJobsNaive(jobs);
	sequenceJobsGreedy(jobs);
}