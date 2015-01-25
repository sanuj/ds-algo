#include <iostream>
using namespace std;
/////////////////////NODE//////////////////////////////////////
typedef struct struct_node {
		int data;
		struct struct_node *next;
} Node;
////////////////////NODE END///////////////////////////////////

/////////////////////QUEUE/////////////////////////////////////
class Queue {
	int front;
	int rear;
	int capacity;
	int size;
	int *array;
public:
	Queue(int capacity);
	int getFront() { return front; };
	int getRear() { return rear; };
	int getCapacity() { return capacity; };
	int getSize() { return size; };
	void enqueue(int data);
	int dequeue();
	void printQueue();
};

Queue::Queue(int capacity) {
	this->capacity = capacity;
	front = size = 0;
	rear = capacity-1;
	array = new int[capacity];
}

void Queue::enqueue(int data) {
	if(size == capacity) {
		cout << "Queue overflow!" << endl;
		return;
	}
	rear = (rear+1)%capacity;
	array[rear] = data;
	size++;
}

int Queue::dequeue() {
	int temp = array[front];
	front = (front+1)%capacity;
	size--;
	return temp;
}

void Queue::printQueue() {
	int temp_size = size;
	int temp_front = front;
	while(temp_size != 0) {
		cout << array[temp_front] << " ";
		temp_front = (temp_front+1)%capacity;
		temp_size--;
	}
	cout << endl;
}
/////////////////////QUEUE END/////////////////////////////////

///////////////////////GRAPH///////////////////////////////////
class Graph {
	int v;
	Node **array;
public:
	Graph(int v);
	void addEdge(int src, int dest);
	int getV() { return v; };
	void printGraph();
	void BFS(int src);
};

Graph::Graph(int v) {
	this->v = v;
	array = new Node*[v];
	for(int i=0; i<v; i++)
		array[i] = NULL;
}

void Graph::addEdge(int src, int dest) {
	Node *temp_dest = new Node[1];
	temp_dest->data = dest;
	temp_dest->next = array[src];
	array[src] = temp_dest;

	Node *temp_src = new Node[1];
	temp_src->data = src;
	temp_src->next = array[dest];
	array[dest] = temp_src;
}

void Graph::printGraph() {
	for(int i=0; i<v; i++) {
		cout << "Vertex " << i << ": ";
		Node *head = array[i];
		while(head != NULL) {
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
}

void Graph::BFS(int src) {
	bool* searched = new bool[v];
	for(int i=0; i<v; i++)
		searched[i] = 0; // set all vertices to be not searched (0)
	Queue queue(v);
	queue.enqueue(src);
	searched[src] = 1; // searched
	while(queue.getSize() != 0) {
		int curr_data = queue.dequeue();
		cout << curr_data << " ";
		Node *head = array[curr_data];
		while(head != NULL) {
			if(!searched[head->data]) {
				queue.enqueue(head->data);
				searched[head->data] = 1; // searched
			}
			head = head->next;
		}
	}
	cout << endl;
}
///////////////////////GRAPH END///////////////////////////////////
/*
				   ___
                   \ /
	0-------1-------5-------6-----9
	 \		|	   / \      |    /|
	  \		|	  /   \     |   / |
	   -----2----3-----4    |  8--10
	   		|    |	   |    | /   |
	   		|	 |	   |    |/    |
	   		----------------7-----11
*/
int main() {
	//Test Queue
	Queue queue(5);
	for(int i=1; i<=5; i++) {
		queue.enqueue(i);
		cout << queue.getFront() << ", " << queue.getRear() << endl;
	}
	cout << "Capacity: " << queue.getCapacity() << endl;
	cout << "Size: " << queue.getSize() << endl;
	cout << "Print Queue: "; queue.printQueue();
	cout << "Dequeued: " << queue.dequeue() << endl;
	cout << "Print Queue: "; queue.printQueue();
	queue.enqueue(10);
	queue.enqueue(20);
	cout << "Dequeued: " << queue.dequeue() << endl;
	queue.enqueue(8);
	cout << "Dequeued: " << queue.dequeue() << endl;
	queue.enqueue(50);
	cout << "Print Queue: "; queue.printQueue();
	
	// Test Graph
	Graph graph(12);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(1, 5);
	graph.addEdge(2, 3);
	graph.addEdge(2, 7);
	graph.addEdge(3, 4);
	graph.addEdge(3, 5);
	graph.addEdge(3, 7);
	graph.addEdge(4, 5);
	graph.addEdge(4, 7);
	graph.addEdge(5, 5);
	graph.addEdge(5, 6);
	graph.addEdge(6, 7);
	graph.addEdge(6, 9);
	graph.addEdge(7, 8);
	graph.addEdge(7, 11);
	graph.addEdge(8, 9);
	graph.addEdge(8, 10);
	graph.addEdge(9, 10);
	graph.addEdge(10, 11);
	cout << graph.getV() << endl;
	graph.printGraph();
	cout << endl;
	cout << "BFS: "; graph.BFS(0);
	return 0;
}