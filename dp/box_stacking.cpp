#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct representing a box
struct Box {
  int w; // width
  int d; // depth
  int h; // height
};

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

/**
 * Used by std::sort function to compare boxes.
 * Helps to sort in descending order of area.
 */
bool compare(const Box &a, const Box &b) {
  return a.w*a.d > b.w*b.d;
}

void stackBoxes(vector<Box> &boxes) {
  // Make a vector which has all rotated orientations of all boxes
  // Assuming width <= depth
  vector<Box> rot_boxes;
  for(int i=0; i<boxes.size(); i++) {
    rot_boxes.push_back(boxes[i]);
    Box *box_a = new Box[1];
    box_a->h = boxes[i].w;
    box_a->d = max(boxes[i].h, boxes[i].d);
    box_a->w = min(boxes[i].h, boxes[i].d);
    rot_boxes.push_back(*box_a);

    Box *box_b = new Box[1];
    box_b->h = boxes[i].d;
    box_b->d = max(boxes[i].h, boxes[i].w);
    box_b->w = min(boxes[i].h, boxes[i].w);
    rot_boxes.push_back(*box_b);
  }

  // Sort them in descending order by area of base
  sort(rot_boxes.begin(), rot_boxes.end(), compare);

  // Apply DP. Same as Longest Increasing Subsequence problem.
  int max_h=0, max_h_ind=0, arr_h[rot_boxes.size()], bottom_box[rot_boxes.size()];
  for(int i=0; i<rot_boxes.size(); i++) {
    arr_h[i] = rot_boxes[i].h;
    bottom_box[i] = i;
    for(int j=0; j<i; j++) {
      if(rot_boxes[i].w < rot_boxes[j].w && rot_boxes[i].d < rot_boxes[j].d &&
        arr_h[j]+rot_boxes[i].h > arr_h[i]) {
        arr_h[i] = arr_h[j]+rot_boxes[i].h;
        bottom_box[i] = j;
      }
    }
    if(max_h < arr_h[i]) {
      max_h = arr_h[i];
      max_h_ind = i;
    }
  }

  // Output the result
  cout << "Maximum height: " << max_h << " acheived by the following sequence of boxes:" << endl;
  int i=max_h_ind;
  while(i >= 0) {
    cout << "h: " << rot_boxes[i].h << ", w: " << rot_boxes[i].w << ", d: " << rot_boxes[i].d << endl;
    if(i == bottom_box[i])
      break;
    i = bottom_box[i];
  }
}

int main() {
  // vector<Box> boxes = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  vector<Box> boxes = { {1, 1, 1}, {1, 2, 2}, {4, 5, 6}, {6, 5, 6}};
  stackBoxes(boxes);
  return 0;
}
