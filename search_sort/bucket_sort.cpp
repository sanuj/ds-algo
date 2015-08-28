#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float> &arr) {
  vector<float> buckets[10];
  for(int i=0; i<arr.size(); i++) {
    int b = 10*arr[i];
    buckets[b].push_back(arr[i]);
  }

  for(int i=0; i<10; i++)
    sort(buckets[i].begin(), buckets[i].end());

  int i=0;
  for(int j=0; j<10; j++) {
    for(int k=0; k<buckets[j].size(); k++)
      arr[i++] = buckets[j][k];
  }
}

int main() {
  vector<float> arr = {0.234, 0.149, 0.845, 0.89, 0.654, 0.45, 0.012, 0.96, 0.342, 0.7, 0.54, 0.28};
  bucketSort(arr);
  for(int i=0; i<arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
