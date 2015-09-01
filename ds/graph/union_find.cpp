#include <iostream>
using namespace std;

struct Edge {
  int node_1;
  int node_2;
};

class Graph {
public:
  Edge *edges;
  int v, e, i;
  Graph(int v, int e);
  void addEdge(int node_1, int node_2);
  void printGraph();
};

Graph::Graph(int v, int e) {
  this->v = v;
  this->e = e;
  this->i = 0;
  this->edges = new Edge[e];
}

void Graph::addEdge(int node_1, int node_2) {
  if(this->i == this->e) {
    cout << "Number of edges exceed the limit." << endl;
    return;
  }
  this->edges[this->i].node_1 = node_1;
  this->edges[this->i].node_2 = node_2;
  this->i++;
}

void Graph::printGraph() {
  for(int j=0; j<this->e; j++)
    cout << this->edges[j].node_1 << "---->" << this->edges[j].node_2 << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Code to implement union find algorithm with path compression and
// union by rank.

struct Elem {
  int set; // Set in which the element belongs
  int rank;
};

/**
 * Returns the set to which the element belongs
 * @sets array of sets
 * @i element whose parent set has to be determined
 */
int findSet(Elem *sets, int i) {
  if(sets[i].set != i) {
    sets[i].set = findSet(sets, sets[i].set);
  }
  return sets[i].set;
}

/**
 * Takes union of two sets
 * @sets array of sets
 * @i first set
 * @j second set
 */
void unionSet(Elem *sets, int i, int j) {
  Elem *i_set = &sets[findSet(sets, i)];
  Elem *j_set = &sets[findSet(sets, j)];

  if(i_set->rank > j_set->rank)
    j_set->set = i_set->set;
  else if(i_set->rank < j_set->rank)
    i_set->set = j_set->set;
  else {
    i_set->set = j_set->set;
    j_set->rank ++;
  }
}
////////////////////////////////////////////////////////////////////////////////

bool detectCycle(Graph &graph) {
  Elem sets[graph.v];
  for(int i=0; i<graph.v; i++) {
    sets[i].set = i;
    sets[i].rank = 0;
  }

  for(int i=0; i<graph.e; i++) {
    cout << "ELEMENT:SET ==> ";
    for(int j=0; j<graph.v; j++) {
      cout << j << ":" << sets[j].set << " ";
    }
    cout << endl;
    int node_1_set = findSet(sets, graph.edges[i].node_1);
    int node_2_set = findSet(sets, graph.edges[i].node_2);

    if(node_1_set == node_2_set)
      return true;

    cout << "Taking union of " << graph.edges[i].node_1 << " and " << graph.edges[i].node_2 << endl;
    unionSet(sets, node_1_set, node_2_set);
  }
  return false;
}

int main() {
  Graph graph(6, 7);
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 3);
  graph.addEdge(3, 5);
  graph.addEdge(1, 4);
  graph.addEdge(1, 5);
  graph.addEdge(4, 5);
  if(detectCycle(graph))
    cout << "A cycle was detected." << endl;
  else
    cout << "There is no cycle in the input graph." << endl;
  // graph.printGraph();
  return 0;
}
