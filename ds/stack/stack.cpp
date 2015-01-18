#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct stacknode {
	int data;
	struct stacknode* next;
} StackNode;

bool isEmpty(StackNode* top) {
	return !top;
}

void push(StackNode* &top, int data) {
	StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
	newNode->data = data;
	newNode->next = top;
	top=newNode;
}

int pop(StackNode* &top) {
	StackNode* temp = top;
	top = top->next;
	int returnData = temp->data;
	free(temp);
	return returnData;	
}

void printStack(StackNode* top) {
	if (!top) return;
	while(top->next) {
		cout << top->data << ", ";
		top = top->next;
	}
	cout << top->data << endl;
}

void popStack(StackNode* &top) {
	while(!isEmpty(top))
		cout << pop(top) << endl;
	cout << "Stack is empty!" << endl;
}

int main() {
	StackNode* top = NULL;
	push(top, 1);
	push(top, 2);
	push(top, 3);
	printStack(top);
	popStack(top);
	printStack(top);
	return 0;
}