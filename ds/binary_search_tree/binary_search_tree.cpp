#include <iostream>
using namespace std;

/* Node in the binary search tree with two children - left and right
*/
typedef struct struct_node {
	int data;
	struct struct_node *left, *right;
} Node;

/* Insert a new node in the tree at the appropriate position.
Two parameters:
node = root of the tree
data = data to be stored in the newly created node
*/
void insert(Node *&node, int data) {
	if(node == NULL) {
		node = new Node[1];
		node->data = data;
		node->left = node->right = NULL;
	}
	else {
		if(node->data > data)
			insert(node->left, data);
		else
			insert(node->right, data);
	}
}

/* Returns height of the tree i.e. deepest height from the node
supplied as a parameter.
*/
int height(Node* node) {
	if(node == NULL) return 0;
	return 1+max(height(node->left), height(node->right));
}

/* Prints a level of the binary tree. (Helper method used in breadth first traversal.)
Two parameters:
level - level to be printed
root - root of the binary tree
*/
void printLevel(int level, Node* root) {
	if(level == 1) {
		cout << root->data << " ";
		return;
	}
	if(root->left)
		printLevel(level-1, root->left);
	if(root->right)
		printLevel(level-1, root->right);
}

/* Breadth first traversal of the tree from the node specified as a parameter.
*/
void printLevelOrder(Node* node) {
	int ht = height(node);
	for(int i=1; i<=ht; i++) {
		printLevel(i, node);
		cout << endl;
	}
}

/* Returns the minimum value in the tree as a pointer to the respective node
One parameter:
node - root of the tree
*/
Node* min(Node* node) {
	Node *temp = node;
	while(temp->left)
		temp = temp->left;
	return temp;
}

/* Returns the minimum value in the tree as a pointer to the respective node
One parameter:
node - root of the tree
*/
Node* max(Node* node) {
	Node *temp = node;
	while(temp->right)
		temp = temp->right;
	return temp;
}

/* Returns pointer to the node of the parent of a node specified as a parameter.
Two parameters:
root - root of the tree
node - node for which the parent has to be identified
*/
Node* getParent(Node* root, Node* node) {
	if(root == NULL || root->left == NULL || root->right == NULL)
		return NULL;
	else if(root->left == node || root->right == node)
		return root;
	else if(root->data <= node->data)
		return getParent(root->right, node);
	else if(root->data >= node->data)
		return getParent(root->left, node);
}

/* Prints the tree by Inorder traversal (Used to print the tree in ascending order)
One parameter:
node - root of the binary tree
Eg:
	2
   / \
  1   4
     / \
    3   5
 output -> 1 2 3 4 5
*/
void printInorder(Node* node) {
	while(node == NULL) return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

/* Returns the node with the searched key (Binary Search)
Two parameters:
root - root of the tree
key - search query
*/
Node* search(Node* root, int key) {
	if(root == NULL)
		return NULL;
	else if(root->data == key)
		return root;
	else if(root->data < key)
		return search(root->right, key);
	else if(root->data > key)
		return search(root->left, key);
}

/* Deletes the node in the tree and rearranges to maintain order.
Two parameters:
root - root of the binary tree
data - data of node to be deleted
*/
Node* deleteNode(Node* root, int data) {
	if(root == NULL)
		return NULL;
	if(root->data > data)
		root->left = deleteNode(root->left, data);
	else if(root->data < data)
		root->right = deleteNode(root->right, data);
	else {
		if(root->left == NULL) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node *temp = min(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

/*
           7
     2          9
 1      5    8      11
      3   6       10   20
                    15     25
                  13   16     30
*/
int main() {
	Node* root = NULL;
	insert(root, 7);
	insert(root, 2);
	insert(root, 9);
	insert(root, 1);
	insert(root, 5);
	insert(root, 8);
	insert(root, 11);
	insert(root, 3);
	insert(root, 6);
	insert(root, 10);
	insert(root, 20);
	insert(root, 15);
	insert(root, 25);
	insert(root, 13);
	insert(root, 16);
	insert(root, 30);
	cout << "Height: " << height(root) << endl;
	printLevelOrder(root);
	cout << "Max: " << max(root)->data << endl;
	cout << "Min: " << min(root)->data << endl;
	cout << "Inorder: ";
	printInorder(root);
	cout << endl;
	cout << "Delete 20" << endl;
	deleteNode(root, 20);
	printLevelOrder(root);
	cout << "Delete 9" << endl;
	deleteNode(root, 9);
	printLevelOrder(root);
	return 0;
}