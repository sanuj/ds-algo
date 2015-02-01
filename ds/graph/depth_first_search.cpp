#include <iostream>
using namespace std;

// Node of an adjacency list which is used to represent a graph.
typedef struct struct_node{
	int data;
	struct struct_node *next;
} Node;

// Class representing a Directed Graph
class Graph {
	int v; // number of vertices
	Node **array; // array storing the lists
	void DFSHelper(int src, int *visited); // recursive helper method for depth first search
public:
	Graph(int v); // constructor for graph
	int getV() { return v; }; // returns number of vertices
	void addEdge(int src, int dest); // function to add an edge in the graph
	void DFS(int src); // depth first search
	void DFS(); // exhaustive depth first search
	void printGraph(); // function to print graph in adjacency list form
};

/* Constructor for Graph
One parameter:
v - number of vertices
*/
Graph::Graph(int v) {
	this->v = v;
	array = new Node*[v];
	for(int i=0; i<v; i++)
		array[i] = NULL;
}

/* Function to add an edge in the Graph
Two parameters:
src - source of the edge
dest - destination of the edge
*/
void Graph::addEdge(int src, int dest) {
	Node *node_src = new Node[1];
	node_src->data = dest;
	node_src->next = array[src];
	array[src] = node_src;

	// Uncomment the following to make the Graph undirectional
	// Node *node_dest = new Node[1];
	// node_dest->data = src;
	// node_dest->next = array[dest];
	// array[dest] = node_dest;
}

/* Recursive helper method for DFS
Two parameters:
src - source
visited - array that keeps track of all the visited vertices
*/
void Graph::DFSHelper(int src, int *visited) {
	if(!visited[src]) {
		cout << src << " ";
		visited[src] = 1;
		Node *node = array[src];
		while(node != NULL) {
			DFSHelper(node->data, visited);
			node = node->next;
		}
	}
}

/* Depth first search
One parameter:
src - source from which DFS should begin
*/
void Graph::DFS(int src) {
	int *visited = new int[v];
	for(int i=0; i<v; i++)
		visited[i] = 0; // set all the nodes to be not visited.
	DFSHelper(src, visited);
}

/* Exhaustive DFS
Traverses the whole graph in DFS manner
*/
void Graph::DFS() {
	int *visited = new int[v];
	for(int i=0; i<v; i++)
		visited[i] = 0; // set all the nodes to be not visited.
	for(int i=0; i<v; i++) {
		if(!visited[i]) {
			DFSHelper(i, visited);
		}
	}
}

/* Prints the graph in adjacency list representation */
void Graph::printGraph() {
	for(int i=0; i<v; i++) {
		Node *node = array[i];
		cout << "Vertex " << i << ": ";
		while(node != NULL) {
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}
}
/*
    1--------->3------>2------>8         10<---
    |          |_______|       |         |     \
    |          |       |_______|         |      \
    |         \|/     \|/               \|/      \
    --->5----->6------>0----->4          12------>13
        |      |      ^
        |    ------   |                 
        |    |    |   |           11----->14
        |   \|/  \|/  |
        ---->7--->9----
*/
int main() {
	Graph graph(15);
	graph.addEdge(1, 3);
	graph.addEdge(1, 5);
	graph.addEdge(3, 2);
	graph.addEdge(3, 6);
	graph.addEdge(5, 6);
	graph.addEdge(5, 7);
	graph.addEdge(2, 8);
	graph.addEdge(2, 0);
	graph.addEdge(2, 6);
	graph.addEdge(6, 0);
	graph.addEdge(6, 9);
	graph.addEdge(6, 7);
	graph.addEdge(7, 9);
	graph.addEdge(8, 0);
	graph.addEdge(9, 0);
	graph.addEdge(0, 4);
	graph.addEdge(10, 12);
	graph.addEdge(12, 13);
	graph.addEdge(13, 10);
	graph.addEdge(11, 14);
	graph.printGraph();
	// DFS Traversal
	cout << "DFS src 1: ";
	graph.DFS(1);
	cout << endl << "DFS src 2: ";
	graph.DFS(2);
	cout << endl << "DFS src 3: ";
	graph.DFS(3);
	cout << endl << "DFS src 6: ";
	graph.DFS(6);
	cout << endl << "Exhaustive DFS: ";
	graph.DFS();
	return 0;
}