#include <iostream>
using namespace std;

// Binary Tree Node
typedef struct node_struct {
	int data;
	struct node_struct *left, *right;
} BTNode;

// Creates a new node for the binary tree.
BTNode* createBTNode(int data) {
	BTNode *new_node = new BTNode[1];
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

/**
 * Depth first traversals
 * 1. Inorder
 * 2. Postorder
 * 3. Preorder
 **/
// Inorder traversal - print left -> root -> right
void printInorder(BTNode *node) {
	if(!node) return;
	else {
		printInorder(node->left);
		cout << node->data << " ";
		printInorder(node->right);
	}
}

// Postorder traversal - print left -> right -> root
void printPostorder(BTNode *node) {
	if(!node) return;
	else {
		printPostorder(node->left);
		printPostorder(node->right);
		cout << node->data << " ";
	}
}

// Preorder traversal - print root -> left -> right
void printPreorder(BTNode *node) {
	if(!node) return;
	else {
		cout << node->data << " ";
		printPreorder(node->left);
		printPreorder(node->right);
	}
}

// Breath First Traversal(Level Order Traversal) using queue
typedef struct queue_struct {
	BTNode** arr;
	int front, rear;
	int capacity, size;
} Queue;

Queue* createQueue(int capacity) {
	Queue* queue = new Queue[1];
	queue->capacity = capacity;
	queue->arr = new BTNode*[capacity];
	queue->front = queue->rear = queue->size = 0;
}

void enqueue(Queue* queue, BTNode *node) {
	if (queue->size < queue->capacity) {
		queue->arr[queue->rear++] = node;
		queue->rear %= queue->capacity;
	}
}

BTNode* dequeue(Queue* queue) {
	BTNode* temp = queue->arr[queue->front];
	queue->front++;
	queue->front %= queue->capacity;
	return temp;
}

void printLevelOrder(BTNode *node) {
	Queue *queue = createQueue(10);
	BTNode* temp_node = node;
	while(temp_node) {
		cout << temp_node->data << " ";
		if(temp_node->left)
			enqueue(queue, temp_node->left);
		if(temp_node->right)
			enqueue(queue, temp_node->right);
		temp_node = dequeue(queue);
	}
	cout << endl;
}

// Number of nodes in the tree
int size(BTNode *root) {
	if(!root)
		return 0;
	else
		return 1+size(root->left)+size(root->right);
}

// Maximum depth of tree
int height(BTNode *root) {
	if(!root)
		return 0;
	else {
		return max(height(root->left), height(root->right))+1;
	}
}

/*  Binary Tree Example
			1
		 /     \
	   2         3
	  / \       / \
     4   5     6   7
    / \
   8   9
   		\
   		 10
*/
int main() {
	BTNode *root = createBTNode(1);
	root->left = createBTNode(2);
	root->right = createBTNode(3);
	root->left->left = createBTNode(4);
	root->left->right = createBTNode(5);
	root->right->left = createBTNode(6);
	root->right->right = createBTNode(7);
	root->left->left->left = createBTNode(8);
	root->left->left->right = createBTNode(9);
	root->left->left->right->right = createBTNode(10);
	printInorder(root);
	cout << endl;
	printPostorder(root);
	cout << endl;
	printPreorder(root);
	cout << endl;
	printLevelOrder(root);
	cout << "Size: " << size(root) << endl;
	cout << "Height: " << height(root) << endl;
	return 0;
}