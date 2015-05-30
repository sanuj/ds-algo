#include <iostream>
using namespace std;

typedef struct struct_node {
	int data;
	struct struct_node *next;
} Node;

class Graph {
	int v;
	Node **array;
	bool DFSHelper(int root, bool visited[], bool traversed_stack[]);
public:
	Graph(int v);
	void addEdge(int src, int dest);
	bool detectCycle();
	void printGraph();
};

Graph::Graph(int v) {
	this->v = v;
	array = new Node*[v];
	for(int i=0; i<v; i++) {
		array[i] = NULL;
	}
}

void Graph::addEdge(int src, int dest) {
	Node *src_node = new Node[1];
	src_node->data = dest;
	Node *temp = array[src];
	array[src] = src_node;
	src_node->next = temp;
}

bool Graph::DFSHelper(int root, bool visited[], bool traversed_stack[]) {
	cout << root << " ";
	if(traversed_stack[root]) return true;
	traversed_stack[root] = true;
	Node *node = array[root];
	while(node) {
		if(visited[node->data] == false) {
			if(DFSHelper(node->data, visited, traversed_stack)) return true;
		}
		node = node->next;
	}
	traversed_stack[root] = false;
	visited[root] = true;
	return false;
}

bool Graph::detectCycle() {
	bool traversed_stack[v];
	bool visited[v];
	for(int j=0; j<v; j++) {
		traversed_stack[j] = false;
		visited[j] = false;
	}
	for(int i=0; i<v; i++) {
		if(visited[i] == false) {
			if(DFSHelper(i, visited, traversed_stack))
				return true;
		}
		
	}
	return false;
}

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
	cout << "Is cycle? " << graph.detectCycle() << endl;
	return 0;
}