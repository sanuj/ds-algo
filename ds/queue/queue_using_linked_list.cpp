#include <iostream>
using namespace std;

typedef struct node_struct {
	int data;
	struct node_struct *next;
} Node;

typedef struct queue_struct {
	Node *front;
	Node *rear;
} Queue;

Queue* createQueue() {
	Queue* new_queue = new Queue[1];
	new_queue->front=NULL;
	new_queue->rear=NULL;
	return new_queue;
}

void enqueue(Queue *queue, int data) {
	Node *new_node = new Node[1];
	new_node->data = data;
	new_node->next = NULL;
	if(queue->rear == NULL) {
		queue->front = queue->rear = new_node;
	}
	else {
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

int dequeue(Queue *queue) {
	int return_data = queue->front->data;
	Node *temp = queue->front;
	queue->front = queue->front->next;
	delete temp;
	return return_data;
}

int front(Queue *queue) {
	return queue->front->data;
}

int rear(Queue *queue) {
	return queue->rear->data;
}

void printQueue(Queue *queue) {
	Node* node = queue->front;
	while(node->next) {
		cout << node->data << ", ";
		node = node->next;
	}
	cout << node->data << endl;
}

int main() {
	Queue *queue = createQueue();
	
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	dequeue(queue);
	enqueue(queue, 5);
	enqueue(queue, 6);
	enqueue(queue, 7);
	dequeue(queue);
	enqueue(queue, 8);

	printQueue(queue);
	
	return 0;
}