#include <iostream>
#include <climits>
using namespace std;

typedef struct queue_struct {
	int front, rear;
	unsigned int capacity, size;
	int *queueArr;
} Queue;

Queue* createQueue(int capacity) {
	Queue* new_queue = new Queue[1];
	new_queue->queueArr = new int[capacity];
	new_queue->front=0;
	new_queue->rear=capacity-1;
	new_queue->capacity=capacity;
	new_queue->size=0;
	return new_queue;
}

void enqueue(Queue* queue, int data) {
	if(queue->capacity > queue->size) {
		queue->rear = (++queue->rear)%queue->capacity;
		queue->queueArr[queue->rear] = data;
		queue->size++;
	}
	else
		cout << "No space in queue." << endl;
}

int dequeue(Queue* queue) {
	int returnVal;
	if(queue->size>0) {
		returnVal=queue->queueArr[queue->front];
		queue->front = (queue->front+1)%queue->capacity;
		queue->size--;
		return returnVal;
	}
	else {
		cout << "Queue is empty!" << endl;
		return INT_MIN;
	}
}

int front(Queue* queue) {
	if(queue->size)
		return queue->queueArr[queue->front];
	else {
		cout << "Queue is empty!" << endl;
		return INT_MIN;
	}
}

int rear(Queue* queue) {
	if(queue->size) 
		return queue->queueArr[queue->rear];
	else {
		cout << "Queue is empty!" << endl;
		return INT_MIN;
	}
}

/* for debugging*/
void printQueue(Queue* queue) {
	cout << "Rear: " << queue->rear << endl;
	cout << "Front: " << queue->front << endl;
	cout << "Front Item: " << queue->queueArr[queue->front] << endl;
	cout << "Rear Item: " << queue->queueArr[queue->rear] << endl;
	cout << "Size: " << queue->size << endl;
	cout << "Capacity: " << queue->capacity << endl;
}

int main() {
	Queue* queue = createQueue(6);
	dequeue(queue);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	dequeue(queue);
	enqueue(queue, 6);
	enqueue(queue, 7);
	dequeue(queue);
	enqueue(queue, 8);
	enqueue(queue, 9);
	dequeue(queue);
	enqueue(queue, 10);
	printQueue(queue);
	return 0;
}