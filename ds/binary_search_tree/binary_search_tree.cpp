#include <iostream>
using namespace std;

typedef struct struct_node {
	int data;
	struct struct_node *left, *right;
} Node;

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

int height(Node* node) {
	if(node == NULL) return 0;
	return 1+max(height(node->left), height(node->right));
}

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

void printLevelOrder(Node* node) {
	int ht = height(node);
	for(int i=1; i<=ht; i++) {
		printLevel(i, node);
		cout << endl;
	}
}

Node* min(Node* node) {
	Node *temp = node;
	while(temp->left)
		temp = temp->left;
	return temp;
}

Node* max(Node* node) {
	Node *temp = node;
	while(temp->right)
		temp = temp->right;
	return temp;
}

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

void printInorder(Node* node) {
	while(node == NULL) return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

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