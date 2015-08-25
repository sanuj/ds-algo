#include <iostream>
#include <stack>
#include <climits>
using namespace std;

struct Node {
  int v;
  int wt;
  Node* next;
};

class Graph {
private:
  int v;
  Node** adj_list;
  void topologicalSort(int src, bool *visited, stack<int> &topo_stack);
public:
  Graph(int v);
  void connect(int src, int dest, int wt);
  void longestPath(int src);
  void printGraph();
};

Graph::Graph(int v) {
  this->v = v;
  this->adj_list = new Node*[this->v];
  for(int i=0; i<v; i++) {
    this->adj_list[i] = NULL;
  }
}

void Graph::connect(int src, int dest, int wt) {
  Node* new_node = new Node;
  new_node->wt = wt;
  new_node->v = dest;
  new_node->next = this->adj_list[src];

  this->adj_list[src] = new_node;
}

void Graph::topologicalSort(int src, bool *visited, stack<int> &topo_stack) {
  if(visited[src] == false) {
    visited[src] = true;
    Node* head = this->adj_list[src];
    while(head != NULL) {
      topologicalSort(head->v, visited, topo_stack);
      head = head->next;
    }
    topo_stack.push(src);
  }
}

void Graph::longestPath(int src) {
  bool visited[this->v];
  for(int i=0; i<this->v; i++)
    visited[i] = false;

  stack<int> topo_stack;
  topologicalSort(src, visited, topo_stack);
  // Node** topo_arr = new Node*[topo_stack.size()];

  // int topo_arr_len=0;
  int dist[this->v];
  for(int i=0; i<this->v; i++)
    dist[i] = INT_MIN;

  dist[src] = 0;

  while(!topo_stack.empty()) {
    int top = topo_stack.top();
    topo_stack.pop();
    if(dist[top] != INT_MIN) {
      Node* head = this->adj_list[top];
      while(head != NULL) {
        dist[head->v] = max(dist[top] + head->wt, dist[head->v]);
        head = head->next;
      }
    }
  }

  for(int i=0; i<this->v; i++) {
    if(dist[i] == INT_MIN)
      cout << "Longest Distance from " << src << " to " << i << ": not possible" << endl;
    else
      cout << "Longest Distance from " << src << " to " << i << ": " << dist[i] << endl;
  }
}

void Graph::printGraph() {
  for(int i=0; i<this->v; i++) {
    cout << "Vertex " << i << ": ";
    Node* head = this->adj_list[i];
    while(head != NULL) {
      cout << "(" << head->v << ", " << head->wt << ") ";
      head = head->next;
    }
    cout << endl;
  }
}

int main() {
  Graph graph(7);
  graph.connect(0, 2, 1);
  graph.connect(0, 1, 4);
  graph.connect(0, 3, 8);
  graph.connect(2, 5, 2);
  graph.connect(2, 4, 6);
  graph.connect(4, 3, 5);
  graph.connect(5, 1, 3);
  graph.connect(5, 6, 7);
  // graph.printGraph();
  graph.longestPath(0);
  cout << endl;
  graph.longestPath(4);
  return 0;
}
