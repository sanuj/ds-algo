#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
} Node;

/**Prints list starting from the supplied pointer.
 * @param list pointer to the begining list
 */
void printList(Node* list) {
	while(list->next != NULL) {
		cout << list->data << ", ";
		list = list->next;
	}
	cout << list->data << endl;
}

/**Creates a node at the begining.
 * @param head head of the list
 * @param data data to save in the node
 */
void pushNode(Node* &head, int data) {
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = head;
	head = new_node;
}

/**Creates a node at the end of the list.
 * @param head head of the list
 * @param data data to save in the node
 */
void appendNode(Node* head, int data) {
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	while (head->next) head = head->next;
	head->next = new_node;
}

/**Creates a node after a specified node.
 * @param node previous node after which a new node is created
 * @param data data to save in the node
 */
void insertNodeAfter(Node* &node, int data) {
	pushNode(node, data);
}

/**Deletes node with the first occurance of the key.
 * @param head head of the linked list
 * @param key search query
 */
void deleteNode(Node* &head, int key) {
	if(head->data == key) {
		Node* temp=head;
		head = head->next;
		free(temp);
		return;
	}
	Node* prev = head, *temp=head->next;
	while (temp != NULL && temp->data != key) {
		prev=temp;
		temp=temp->next;
	}
	if (temp != NULL) {
		prev->next = temp->next;
		free(temp);
	}
	else {
		cout << "Element not found!" << endl;
	}
}

/**Deletes the provided node
 * @param node node to be deleted
 */
void deleteNode(Node* &node) {
	if(node != NULL) {
		if(node->next != NULL) {
			Node* temp = node->next;
			node->data = temp->data;
			node->next = temp->next;
			free(temp);
		}
		else {
			// if the node supplied is the last one.
			free(node);
			node=NULL;
		}
	}
}

void printMid(Node* head) {
	Node* slow = head;
	Node* fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	if (fast->next == NULL) {
		cout << "Middle element is: " << slow->data << endl;
	} else {
		cout << "Middle elements are: " << slow->data << ", " << slow->next->data << endl;
	}
}

int main() {
	Node* head = (Node*) malloc(sizeof(Node));  //check what happens with new.
	head->data=0;
	pushNode(head, -1);
	pushNode(head, -2);
	appendNode(head, 1);
	insertNodeAfter(head->next->next, 34);
	appendNode(head, 2);
	printList(head);
	//deleteNode(head, 34);
	deleteNode(head);
	printList(head);
	printMid(head);
	//deleteNode(head, -2);
	deleteNode(head->next->next);
	printList(head);
	printMid(head);
	//deleteNode(head, 2);
	deleteNode(head->next->next->next);
	printList(head);
	//deleteNode(head, 3);
	printList(head);
	return 0;
}
