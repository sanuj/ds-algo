#include <iostream>
#include <cmath>
using namespace std;

class Heap {
  int size;
  int *arr;
  void heapify(int i, int size);
public:
  Heap(int *arr, int size);
  void swap(int i, int j);
  int left(int i) {return 2*i+1;}
  int right(int i) {return 2*i+2;}
  void print();
  int height();
  void heapSort();
};

Heap::Heap(int *arr, int size) {
  this->size = size;
  this->arr = arr;
  for(int i = this->size-1; i >= 0; --i) {
    heapify(i, this->size);
  }
}

inline int Heap::height() {
	if(this->size == 0)
		return 0;
	return log2(this->size);
}

void Heap::swap(int i, int j) {
  // cout << "swapping" << endl;
  int temp = this->arr[i];
  this->arr[i] = this->arr[j];
  this->arr[j] = temp;
}

void Heap::heapify(int i, int size) {
  // cout << "calling heapify" << endl;
  if(left(i) < size) {
    if(this->arr[i] > this->arr[left(i)]) {
      // cout << "inside" << endl;
      swap(i, left(i));
      heapify(left(i), size);
    }
  }
  if(right(i) < size) {
    if(this->arr[i] > this->arr[right(i)]) {
      swap(i, right(i));
      heapify(right(i), size);
    }
  }
}

void Heap::print() {
  int i=0;
	for(int j=0; j<=height(); j++) {
		int k = pow(2,j);
		while(k-- && i < this->size) {
			cout << this->arr[i++] << " ";
		}
		cout << endl;
	}
}

void Heap::heapSort() {
  int temp[this->size];
  int temp_size = this->size;
  int i=0;
  while(temp_size != 0) {
    temp[i++] = this->arr[0];
    swap(0, temp_size-1);
    temp_size--;
    heapify(0, temp_size);
  }

  for(int i=0; i<this->size; i++)
    this->arr[i] = temp[i];
}

int main() {
  int arr[] = {3, 5, 5, 2, 7, 1, 8, 6, 9, 0, 10, 32, 45, 3, 6, 27, 0, 14};
  int size = 18;
  Heap heap(arr, size);
  heap.heapSort();
  heap.print();
  return 0;
}
