#pragma once

#include <iostream>
#include <stdlib.h>
class Stack
{
public:
	Stack();			// initiate default stack with default size.
	Stack(int size);	// initiate stack with set size.
	void push(int x);	// push integer onto stack.
	int peek();			// peek at integer at the top of the stack.
	int pop();			// pop top of stack and return element popped.
	bool isStackEmpty();
	bool isStackFull();
	~Stack();
private:
	void resizeStack(int newSize);

	int *stack;
	int top = -1;
	int size = 0;
	bool isEmpty = true;
};

