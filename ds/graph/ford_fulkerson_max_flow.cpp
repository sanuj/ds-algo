#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/**
 * Function to print graph
 * @graph input graph to be printed
 */
void printGraph(vector< vector<int> > &graph) {
  for(int i=0; i<graph.size(); i++) {
    for(int j=0; j<graph[i].size(); j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
}

/**
 * Breadth First Search
 * @graph input graph
 * @s source
 * @t sink or terminal
 * @parent vector to store parent node of each node in breadth first traversal
 */
bool bfs(vector< vector<int> > &graph, int s, int t, vector<int> &parent) {
  queue<int> q;
  q.push(s);
  vector<bool> visited(graph.size(), false);
  visited[s] = true;
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    for(int i=0; i<graph.size(); i++) {
      if(graph[node][i] != 0 && !visited[i]) {
        q.push(i);
        parent[i] = node;
        visited[i] = true;
      }
    }
  }
  return visited[t];
}

/**
 * Ford Fulkerson algorithm to find max flow
 * @graph input graph
 * @s source
 * @t sink or terminal
 */
void findMaxFlow(vector< vector<int> > &graph, int s, int t) {
  vector< vector<int> > r_graph;
  for(int i=0; i<graph.size(); i++)
    r_graph.push_back(graph[i]);

  vector<int> parent(r_graph.size(), 0);
  parent[s] = -1;
  int max_flow = 0;
  while(bfs(r_graph, s, t, parent)) {
    int aug_path_flow = INT_MAX;
    for(int i=t; i != s; i=parent[i]) {
      if(aug_path_flow > r_graph[parent[i]][i])
        aug_path_flow = r_graph[parent[i]][i];
    }

    for(int i=t; i != s; i=parent[i]) {
      r_graph[parent[i]][i] -= aug_path_flow;
      r_graph[i][parent[i]] += aug_path_flow;
    }
    max_flow += aug_path_flow;
  }
  cout << "Residual graph in the end: " << endl;
  printGraph(r_graph);
  cout << "Maximum flow from source " << s << " to sink " << t << " is " << max_flow << endl;
}

int main() {
  vector< vector<int> > graph = { {0, 16, 13, 0, 0, 0, 3},
                                  {0, 0, 10, 12, 0, 0, 4},
                                  {0, 4, 0, 0, 14, 0, 5},
                                  {0, 0, 9, 0, 0, 20, 9},
                                  {0, 0, 0, 7, 0, 4, 6},
                                  {0, 0, 0, 0, 0, 0, 8},
                                  {1, 3, 5, 0, 0, 0, 9},
                                };
  findMaxFlow(graph, 0, 6);
  return 0;
}
