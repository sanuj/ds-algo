#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int divide(vector<int> &arr, int begin, int end) {
  // taking end element as pivot i.e. pivot value is arr[end]
  int i = begin;
  for(int j=begin; j<end; ++j) {
    // comparing with value of pivot
    if(arr[j] < arr[end]) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  // placing pivot at it's correct position
  swap(arr[i], arr[end]);
  return i;
}

/**
 * Recursive function to sort the input array
 * Implements quick sort
 * @arr input array
 * @b begin
 * @e end
 */
void quickSort(vector<int> &arr, int begin, int end) {
  if(begin < end) {
    // dividing is the hard part unlike merge sort
    int pivot = divide(arr, begin, end);
    quickSort(arr, begin, pivot-1);
    quickSort(arr, pivot+1, end);
  }
}

int main() {
  vector<int> arr = {2, 5, 6, 58, 32, 12, 68, 72, 31, 47, 6, 4, 6, 77, 13, 34, 6, 5, 3, 34, 3, 43, 1, 233, 6757, 23, 56};
  quickSort(arr, 0, arr.size()-1);
  for(int i=0; i<arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
