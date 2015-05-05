/*
This implements Depth First Search using a LIFO stack.
*/
#include <iostream>
#include <climits>
using namespace std;

//Node struct used to make the stack
typedef struct struct_node{
	int data;
	struct struct_node *next;
} Node;

// Class implementing stacks
class Stack {
	// Private Variables
	int size;
	Node *top; // Pointer to the top of the stack
public:
	Stack(); // Constructor
	void push(int data); // add data on top of the stack
	int pop(); // remove data from the top of the stack
	int peek(); // see data on top of the stack
	void printStack(); // print the whole stack
	int getSize() { return size; }; // return the private size variable
};

// Constructor for the Stack
Stack::Stack() {
	size = 0;
	top = NULL;
}

void Stack::push(int data) {
	Node *new_node = new Node[1];
	new_node->data = data;
	new_node->next = top;
	top = new_node;
	size++;
}

int Stack::pop() {
	if(top != NULL) {
		int return_val = top->data;
		Node *temp = top;
		top = top->next;
		delete temp;
		size--;
		return return_val;
	}
	return INT_MIN;
}

int Stack::peek() {
	if(top != NULL)
		return top->data;
	return INT_MIN;
}

void Stack::printStack() {
	Node *temp = top;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Class to implement Graphs
class Graph {
	// Private Members
	int v; // number of vertices
	Node **array; // array for making the adjacency list
	void DFSHelper(int src, int *visited); // Private helper function for depth first search
public:
	Graph(int v); // Constructor for graph
	int getV() { return v; }; // Return the number of vertices
	void addEdge(int src, int dest); // Add an edge to the graph from source to destination
	void DFS(int src); // Member function to implement Depth First Search
	void printGraph(); // Member function to print the whole graph
};

// Constructor
Graph::Graph(int v) {
	this->v = v;
	array = new Node*[v];
	for(int i=0; i<v; i++)
		array[i] = NULL;
}

// Adds directional edge
void Graph::addEdge(int src, int dest) {
	Node *node_src = new Node[1];
	node_src->data = dest;
	node_src->next = array[src];
	array[src] = node_src;

	// Node *node_dest = new Node[1];
	// node_dest->data = src;
	// node_dest->next = array[dest];
	// array[dest] = node_dest;
}

// Implementing Depth First Search using a stack
void Graph::DFS(int src) {
	int *visited = new int[v];
	for(int i=0; i<v; i++)
		visited[i] = 0; // set every node to not visited
	Stack stack;
	stack.push(src);
	while(stack.getSize() != 0) {
		int curr = stack.pop();
		if(!visited[curr]) {
			cout << curr << " ";
			visited[curr] = 1;
			Node *node = array[curr];
			while(node != NULL) {
				stack.push(node->data);
				node = node->next;
			}
		}
	} 
}

// Prints the whole graph
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
    1--------->3------>2------>8
    |          |_______|       |
    |          |       |_______|
    |         \|/     \|/
    --->5----->6------>0----->4
        |      |      ^
        |    ------   |
        |    |    |   |
        |   \|/  \|/  |
        ---->7--->9----
*/
int main() {
	// Stack Test
	Stack stack;
	stack.push(3);
	stack.push(6);
	stack.push(1);
	stack.push(7);
	stack.printStack();
	cout << "Pop: " << stack.pop() << endl;
	stack.push(9);
	cout << "Peek: " << stack.peek() << endl;
	stack.printStack();
	// Graph Test
	Graph graph(10);
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
	return 0;
}