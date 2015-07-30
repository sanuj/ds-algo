#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int edit_distance(string &a, string &b) {
  int dist[a.size()+1][b.size()+1];

  cout << "String A: ";
  for(int i=0; i<a.size(); i++)
  	cout << a[i];
  cout << endl << "String B: ";
  for(int i=0; i<b.size(); i++)
  	cout << b[i];
  cout << endl << "Algorithm converts string B --> A" << endl;

  ///// Computing Distance Matrix /////////
  for(int i=0; i<=a.size(); i++)
    dist[i][0] = i;
  for(int j=0; j<=b.size(); j++)
    dist[0][j] = j;

  for(int i=1; i<=a.size(); i++) {
    for(int j=1; j<=b.size(); j++) {
      int minimum = min(dist[i-1][j-1], min(dist[i-1][j], dist[i][j-1]));
      if(a[i-1] == b[j-1])
        dist[i][j] = minimum;
      else
        dist[i][j] = minimum+1;
    }
  }
  cout << "Distance Matrix: " << endl;
  for(int i=0; i<=a.size(); i++) {
    for(int j=0; j<b.size(); j++) {
      cout << dist[i][j] << ", ";
    }
    cout << dist[i][b.size()] << endl;
  }

  ////// Finding Add/Delete/Substitute steps by traversing the Distance Matrix ////////
  int i=a.size(), j=b.size();
  cout << endl << "Minimum steps required: " << dist[i][j] << endl;
  cout << "** Starting from the right." << endl;
  int pred[2]; // array defined to store predecessors
  while(i != 0 || j != 0) {
  	
  	if(i-1 >= 0 && j-1 >=0) {
		int minimum = min(dist[i-1][j-1], min(dist[i-1][j], dist[i][j-1]));
		for(int m=i-1; m<i+1; m++) {
			for(int n=j-1; n<j+1; n++) {
				if(dist[m][n] == minimum && !(m == i && n == j)) {
					pred[0] = m, pred[1] = n;
					m = i+1, n = j+1; // breaks the nested for loops
				}
			}
		}
	}
	else if(i == 0)
		pred[0] = i, pred[1] = j-1;
	else if(j == 0)
		pred[0] = i-1, pred[1] = j;

	int diff_x = i-pred[0], diff_y = j-pred[1];
	if(a[i-1] != b[j-1]) {
		if(diff_x == 1 && diff_y ==1)
			cout << "** Substitute " << b[j-1] << " with " << a[i-1] << " in string B" << endl;
		else if(diff_y == 1)
			cout << "** Delete " << b[j-1] << " from string B." << endl;
		else if(diff_x == 1)
			cout << "** Add " << a[i-1] << " to string B." << endl;
	}
	else {
		if(diff_y == 1 && diff_x == 0)
			cout << "** Delete " << b[j-1] << " from string B." << endl;
		else if(diff_x == 1 && diff_y == 0)
			cout << "** Add " << a[i-1] << " to string B." << endl;
	}
  	i = pred[0], j = pred[1];
  }
  return 0;
}

int main() {
  string a = "communication";
  string b = "computation";
  edit_distance(a, b);
  cout << endl;
  a = "star";
  b = "stamp";
  edit_distance(a, b);
  cout << endl;
  // a = "sdgdg";
  // b = "fgjgjjfgbfg";
  // edit_distance(a, b);
  return 0;
}
