#include <iostream>
#include <climits>
using namespace std;

typedef struct struct_node{
	int data;
	struct struct_node *next;
} Node;

class Stack {
	int size;
	Node *top;
public:
	Stack();
	void push(int data);
	int pop();
	int peek();
	void printStack();
	int getSize() { return size; };
};

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

class Graph {
	int v;
	Node **array;
	void DFSHelper(int src, int *visited);
public:
	Graph(int v);
	int getV() { return v; };
	void addEdge(int src, int dest);
	void DFS(int src);
	void printGraph();
};

Graph::Graph(int v) {
	this->v = v;
	array = new Node*[v];
	for(int i=0; i<v; i++)
		array[i] = NULL;
}

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