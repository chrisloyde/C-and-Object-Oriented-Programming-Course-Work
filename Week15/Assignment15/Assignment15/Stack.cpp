#include "Stack.h"

Stack::Stack() {
	stack = new int[5];						// default size of stack is 5.
	size = 5;
}

Stack::Stack(int s) {
	stack = new int[s];						// set stack size to instructed size.
	size = s;
}

void Stack::push(int x) {
	++top;									// increment top to get position to push to.
	if (!isStackFull()) {					// if the stack isn't full we can push the element.
		stack[top] = x;
	}
	else {									// if stack is full then we need to resize the stack.
		resizeStack(size + size);			// resize the stack to double its size. 
		stack[top] = x;						// push element onto stack.
	}
	isEmpty = false;						// since an element was just pushed stack is no longer empty.
}

int Stack::peek() {
	if (isStackEmpty()) {					// can't peek and empty stack so print a message and return an error number.
		std::cerr << "Attempted to peek on an empty stack!" << std::endl;
		return -999;
	}
	return stack[top];
}

int Stack::pop() {
	if (isStackEmpty()) {					// can't pop and empty stack so print a message and return an error number.
		std::cerr << "Attempted to pop on an empty stack!" << std::endl;
		return -999;
	}

	--top;									// decrement top to move down a place in the stack.

	if (top == -1) {						// check if we've empties the stack, adjust variable
		isEmpty = true;
	}

	return stack[top + 1];					// return the element at top + 1 (add 1 since we just decremented top).
}

bool Stack::isStackEmpty() {
	return isEmpty;
}

bool Stack::isStackFull() {
	return (top >= size);					// stack is full if the top value is equal to or greater then the size.
}

void Stack::resizeStack(int newSize) {
	int *temp = new int[newSize];			// create a new array of the new size.	

	for (int i = 0; i < size; i++) {		// copy values from old stack to new stack.
		temp[i] = stack[i];
	}

	delete[] stack;							// delete old stack.

	stack = temp;							// assign stack pointer to new stack.
	size = newSize;							// set size to new size.
}

Stack::~Stack() {
	delete[] stack;
}
