#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * This problem is about traversing a 2-D table of numbers by following the minimum cost path.
 * The value of (i, j) in the table is the cost to include that element in your path.
 * You are only allowed to go right, down, diagonally down (bottom-right).
 */

/**
 * Bottom Up (Tabulation) approach for a solution using dynamic programming
 */
int min_cost_path_BU(vector<vector<int> > &grid, int x, int y) {
  int m=grid.size(), n=grid[0].size();
  int mcp[m][n];
  cout << "Minimum Cost Path Table:" << endl;
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      if(i==0 && j==0)
        mcp[i][j] = grid[i][j];
      else if(i==0)
        mcp[i][j] = mcp[i][j-1] + grid[i][j];
      else if(j==0)
        mcp[i][j] = mcp[i-1][j] + grid[i][j];
      else
        mcp[i][j] = min(mcp[i-1][j-1], min(mcp[i-1][j], mcp[i][j-1])) + grid[i][j];
    }
  }
  for(int i=0; i<m; i++) {
    for(int j=0; j<n-1; j++) {
      cout << mcp[i][j] << ", ";
    }
    cout << mcp[i][n-1] << endl;
  }
  return mcp[x][y];
}

/**
 * This approach can be converted to use memoization (dynamic programming)
 * Just add a dictionary
 * Save newly computed values
 * Look up already calculated values from that to remove redundancy.
 */
int min_cost_path(vector<vector<int> > &grid, int x, int y) {
  if(x==0 && y==0)
    return grid[x][y];
  else if(x==0) {
    return grid[x][y]+min_cost_path(grid, x, y-1);
  }
  else if(y==0) {
    return grid[x][y]+min_cost_path(grid, x-1, y);
  }
  else {
    return grid[x][y]+min(min_cost_path(grid, x-1, y-1), min(min_cost_path(grid, x, y-1), min_cost_path(grid, x-1, y)));
  }
  // for(int i=0; i<grid.size(); i++) {
  //   for(int j=0; j<grid[i].size(); j++) {
  //     cout << grid[i][j] << ", ";
  //   }
  //   cout << endl;
  // }
}

int main() {
  vector< vector<int> > grid = {{1, 2, 3, 5},
                                {4, 8, 2, 6},
                                {1, 5, 3, 7}};
  // cout << "Minimum Cost Path: " << min_cost_path(grid, 1, 3) << endl;
  cout << "Minimum Cost Path: " << min_cost_path_BU(grid, 1, 3) << endl;
  return 0;
}
