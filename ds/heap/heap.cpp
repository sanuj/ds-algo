#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

//Minimum Heap using an array of integers
typedef struct struct_heap {
	int *arr;
	int capacity;
	int size;
} Heap;

/* Creates a new heap and returns a pointer to it.
One parameter:
capacity - maximum capacity of an the heap when it is full
*/
Heap* createHeap(int capacity) {
	Heap *new_heap = new Heap[1];
	new_heap->capacity = capacity;
	new_heap->size = 0;
	new_heap->arr = new int[capacity];
	return new_heap;
}

/* Returns left index of the index passed in the parameter */
inline int left(int i) {return 2*i+1;}

/* Returns right index of the index passed in the parameter */
inline int right(int i) {return 2*i+2;}

/* Returns parent index of the index passed in the parameter */
inline int parent(int i) {return (i-1)/2;}

/* Returns height of the heap passed as a parameter
One parameter:
heap - pointer to the heap
*/
inline int height(Heap *heap) {
	if(heap->size == 0)
		return 0;
	return log2(heap->size);
}

/* Inserts a new integer in the heap so that the property of
a heap is maintained
Two parameters:
heap - pointer to the heap
key - integer that has to be inserted
*/
void insert(Heap *heap, int key) {
	if(heap->size == heap->capacity) {
		cout << "Heap overflow!" << endl;
		return;
	}
	int i = heap->size;
	heap->arr[i] = key;
	while(i >0 && heap->arr[i] < heap->arr[parent(i)]) {
		int temp = heap->arr[i];
		heap->arr[i] = heap->arr[parent(i)];
		heap->arr[parent(i)] = temp;
		i = parent(i); 
	}
	heap->size++;
}

/* Prints the heap passed as a parameter. */
void printHeap(Heap *heap) {
	int i=0;
	for(int j=0; j<=height(heap); j++) {
		int k = pow(2,j);
		while(k-- && i < heap->size) {
			cout << heap->arr[i++] << " ";
		}
		cout << endl;
	}
}

/* Returns minimum element in the heap
It is the root element in a Minimum heap.
*/
inline int getMin(Heap *heap) {
	if(heap->size == 0)
		return INT_MIN;
	else
		return heap->arr[0];
}

/* Makes sure that the property of a heap is maintained considering the
heap originating from index i. It assumes that the child-heaps ie. i--->left
and i--->right are proper heaps and index i is the only element that might be
at the wrong place.
Two parameters:
heap - pointer to the heap
i - index which has to be 'heapified'
*/
void minHeapify(Heap *heap, int i) {
	int temp_i = i;
	if(left(i) < heap->size && heap->arr[i] > heap->arr[left(i)])
		temp_i = left(i);
	if(right(i) < heap->size && heap->arr[temp_i] > heap->arr[right(i)])
		temp_i = right(i);
	if(temp_i != i) {
		int temp = heap->arr[i];
		heap->arr[i] = heap->arr[temp_i];
		heap->arr[temp_i] = temp;
		minHeapify(heap, temp_i);
	}
}

/* Removes and returns the minimumm (root) element of the heap.
One parameter:
heap - pointer to the heap
*/
int extractMin(Heap* heap) {
	int min = INT_MIN;
	if(heap->size == 1) {
		heap->size--;
		return heap->arr[0];
	}
	else if(heap->size > 1) {
		min = heap->arr[0];
		heap->arr[0] = heap->arr[--heap->size];
		minHeapify(heap, 0);
	}
	return min;
}

/* Decreases the value of the element at index 'i' to 'key' and rearranges
it in the heap.
Three parameters:
heap - pointer to the heap
i - index of the element that has to be decreased
key - new (decreased) value of the element
*/
void decreaseKey(Heap* heap, int i, int key) {
	heap->arr[i] = key;
	while(i != 0 && heap->arr[i] < heap->arr[parent(i)]) {
		int temp = heap->arr[i];
		heap->arr[i] = heap->arr[parent(i)];
		heap->arr[parent(i)] = temp;
		i = parent(i);
	}
}

/* Deletes an element at index 'i' in the heap
Two parameters:
heap - pointer to the heap
i - index of the element that has to be deleted.
*/
void deleteKey(Heap* heap, int i) {
	decreaseKey(heap, i, INT_MIN);
	extractMin(heap);
}

int main() {
	Heap *heap = createHeap(20);
	int a[] = {3, 2, 5, 30, 40, 50, 60, 1, 4, 6, 7, 10, 20};
	int a_len = 13;
	for(int i=0; i<a_len; i++) {
		insert(heap, a[i]);
		cout << "size, capacity: " << heap->size << ", " << heap->capacity << endl; 
		cout << "Height: " << height(heap) << endl;
	}
	printHeap(heap);
	cout << "-------------DecreseKey---------------" << endl;
	decreaseKey(heap, 6, 25);
	printHeap(heap);
	cout << "-------------DeleteKey---------------" << endl;
	deleteKey(heap, 3);
	printHeap(heap);
	cout << "-------------------------------------" << endl;
	while(heap->size != 0) {
		cout << "Min: " << extractMin(heap) << endl;
		printHeap(heap);
	}
	return 0;
}