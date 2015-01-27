#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

typedef struct stackStruct {
	int top;
	int size;
	char *stackArr;
} Stack;

Stack* createStack(int size) {
	Stack* new_stack = (Stack*) malloc(sizeof(Stack));
	new_stack->top=-1;
	new_stack->size=size;
	new_stack->stackArr = (char*) malloc(size*sizeof(char));
	return new_stack;
}

void push(Stack* stack, char inp) {
	if (stack->size > stack->top+1)
		stack->stackArr[++stack->top] = inp;
	else
		cout << "No space in stack!" << endl;
}

char pop(Stack* stack) {
	if (stack->top > -1)
		return stack->stackArr[stack->top--];
	else {
		cout << "Stack is empty!" << endl;
		return '$';
	}
}

char peek(Stack* stack) {
	if (stack->top > -1)
		return stack->stackArr[stack->top];
	else {
		//cout << "Stack is empty!" << endl;
		return '$'; //for empty stack
	}
}

void printStack(Stack *stack) {
	if(stack->top<0) return;
	for(int i=stack->top; i>0; i--)
		cout << stack->stackArr[i] << ", ";
	cout << stack->stackArr[0] << endl;
}

int precedence(char op) {
	if(op=='^')
		return 4;
	else if(op=='/')
		return 3;
	else if(op=='*')
		return 2;
	else if(op=='+' || op=='-')
		return 1;
	return 0;
}

bool isDigit(char ch) {
	return ch >='0' && ch<='9';
}

string infix2postfix(string exp) {
	string returnExp="";
	Stack *stack = createStack(100);
	for(int i=0; i<exp.size(); i++) {
		if(isDigit(exp[i]))
			returnExp.push_back(exp[i]);
		else if(exp[i] == '(')
			push(stack, exp[i]);
		else if(exp[i] == ')') {
			while(peek(stack) != '(')
				returnExp.push_back(pop(stack));
			pop(stack);
		}
		else if(peek(stack) != '$' && (precedence(exp[i]) > precedence(peek(stack))))
			push(stack, exp[i]);
		else if(peek(stack) != '$' && (precedence(exp[i]) < precedence(peek(stack)))) {
			while(precedence(exp[i]) < precedence(peek(stack)))
				returnExp.push_back(pop(stack));
			push(stack, exp[i]);
		}
		else
			push(stack, exp[i]);
	}
	while(peek(stack) != '$')
		returnExp.push_back(pop(stack));
	return returnExp;
}

int evaluatePostfix(string exp) {
	Stack *stack = createStack(100);
	for(int i=0; i<exp.size(); i++) {
		if(isDigit(exp[i]))
			push(stack, exp[i]);
		else{
			int operand1 = pop(stack)-'0';
			int operand2 = pop(stack)-'0';
			int operand3=0;
			switch(exp[i]) {

				case '+': operand3=operand2+operand1; break;
				case '-': operand3=operand2-operand1; break;
				case '*': operand3=operand2*operand1; break;
				case '^': operand3=operand2^operand1; break;
				case '/': operand3=operand2/operand1; break;
			}
			push(stack, operand3+'0');
		}
	}
	return pop(stack)-'0';
}

int main() {
	cout << "1+2*3+4: " << infix2postfix("1+2*3+4") << endl;
	cout << "1*(2+3)/4+5: " << infix2postfix("1*(2+3)/4+5") << endl;
	cout << "2/3*4-1/4*(2+3): " << infix2postfix("2/3*4-1/4*(2+3)") << endl;
	cout << "1+2*(3^4-5)^(6+7*8)-9: " << infix2postfix("1+2*(3^4-5)^(6+7*8)-9") << endl;
	cout << "231*+9-: " << evaluatePostfix("231*+9-") << endl;
	cout << evaluatePostfix(infix2postfix("1+2*(3^4-5)^(6+7*8)-9")) << endl;
	int a=1, b=2, c=3, d=4, e=5, f=6, g=7, h=8, i=9;
	cout << a+b*pow((pow(c,d)-e),(f+g*h))-i << endl;
	return 0;
}