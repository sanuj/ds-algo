#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node *l;
  Node *r;
};

Node* createNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->l = NULL;
  node->r = NULL;
  return node;
}

// Breadth first search using queues
void printTree(Node *root) {
  if(root == NULL)
    return;
  queue<Node*> q;
  q.push(root);
  int i=0, j=0;
  while(!q.empty()) {
    i++;
    Node *node = q.front();
    q.pop();
    cout << node->data << " ";
    if(i % (int)pow(2, j) == 0) {
      cout << endl;
      i=0;
      j++;
    }
    Node *left = node->l;
    Node *right = node->r;
    if(left != NULL) q.push(left);
    if(right != NULL) q.push(right);
  }
}

/**
 * Utility function to print Binary Tree vertically
 * @root tree's root
 * @h_dist horizontal distance
 * @m map
 */
void verticalPrintTreeUtil(Node *root, int h_dist, map<int, vector<int> > &m) {
  m[h_dist].push_back(root->data);
  if(root->l != NULL)
    verticalPrintTreeUtil(root->l, h_dist-1, m);
  if(root->r != NULL)
    verticalPrintTreeUtil(root->r, h_dist+1, m);
}

void verticalPrintTree(Node *root) {
  if(root == NULL)
    return;
  map<int, vector<int> > m;
  int h_dist = 0;
  verticalPrintTreeUtil(root, h_dist, m);
  map<int, vector<int> > :: iterator it;
  for (it=m.begin(); it!=m.end(); ++it)
  {
      for (int i=0; i<it->second.size(); ++i)
          cout << it->second[i] << " ";
      cout << endl;
  }
}
/*
                1
        2               3
    4       5       6       7
  8   9   10  11  12 13   14 15
*/
int main() {
  Node *root = createNode(1);
  root->l = createNode(2);
  root->r = createNode(3);
  root->l->l = createNode(4);
  root->l->r = createNode(5);
  root->r->l = createNode(6);
  root->r->r = createNode(7);
  root->l->l->l = createNode(8);
  root->l->l->r = createNode(9);
  root->l->r->l = createNode(10);
  root->l->r->r = createNode(11);
  root->r->l->l = createNode(12);
  root->r->l->r = createNode(13);
  root->r->r->l = createNode(14);
  root->r->r->r = createNode(15);
  // printTree(root);
  verticalPrintTree(root);
  return 0;
}

// Note: std::map used here is actually implemented by using a BST under the
// hood so it's not hashing but a binary search tree. If you want to use hashing
// to solve this problem then use std::unordered map.
