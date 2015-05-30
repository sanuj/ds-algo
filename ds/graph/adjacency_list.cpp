#include <iostream>
using namespace std;

typedef struct struct_node {
	int dest; // destination
	struct struct_node *next;
} Node;

// Undirected graph
typedef struct struct_graph {
	int v; //number of vertices
	Node **array;
} Graph;

// Returns a node for the provided destination.
Node* createNode(int dest) {
	Node* new_node = new Node[1];
	new_node->dest = dest;
	new_node->next = NULL;
	return new_node;
}

// Returns a graph with 'v' vertices.
Graph* createGraph(int v) {
	Graph* new_graph = new Graph[1];
	new_graph->v = v;
	new_graph->array = new Node*[v];
	for(int i=0; i<v; i++)
		new_graph->array[i] = NULL;
	return new_graph;
}

// Adds an edge from src to dest(and dest to src) in graph (undirectional)
void addEdge(Graph *graph, int src, int dest) {
	if(src < graph->v && dest < graph->v) {
		Node *temp_dest = createNode(dest);
		temp_dest->next = graph->array[src];
		graph->array[src] = temp_dest;

		Node *temp_src = createNode(src);
		temp_src->next = graph->array[dest];
		graph->array[dest] = temp_src;
	}
	else
		cout << "Graph Overflow!" << endl;
}

void printGraph(Graph *graph) {
	for(int i=0; i<graph->v; i++) {
		cout << "Vertex " << i << ": ";
		Node* head = graph->array[i];
		while(head != NULL) {
			cout << head->dest << " ";
			head = head->next;
		}
		cout << endl;
	}
}

/*
	0-------1-------5
	 \		|	   / \
	  \		|	  /   \
	   -----2----3-----4
*/
int main() {
	Graph *graph = createGraph(6);
	addEdge(graph, 0, 1);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 5, 1);
	addEdge(graph, 2, 0);
	addEdge(graph, 3, 5);
	printGraph(graph);
	return 0;
}