/*
Exercise 19.13 pg 836-837 (Postfix Evaluation)
*/

#include <iostream>
#include <string>
#include "Stack.h"

int evaluatePostfixExpression(Stack *stack, const char *expression);
bool isCharAnInteger(char c);
bool isCharAnOperand(char c);

int main() {
	char inBuff[512];										// input buffer
	Stack *stack = new Stack();

	printf("Enter string to perform Postfix evaluation on (only evaluations integers 0-9): \n");
	fgets(inBuff, 100, stdin);								// get input from stdin
	strtok(inBuff, "\n");									// sanitize input by clearing the \n from enter
	printf("%s = %d\n", 
		inBuff, evaluatePostfixExpression(stack, inBuff));	// print result

	delete stack;
	printf("\nPress Enter to Quit\n");
	getchar();
	return 0;
}


/*
Modifies stack.
Does not pop the result off the stack.
*/
int evaluatePostfixExpression(Stack *stack, const char *expression) {
	char c;
	int exSize = strlen(expression);
	int x, y, z;

	for (int i = 0; i < exSize; i++) {
		c = expression[i];
		if (isCharAnInteger(c)) {							// push character if it is an integer.
			stack->push(((int)c)-48);						// convert from character to integer.
		}
		else if (isCharAnOperand(c)) {						// check if c is a valid operand, if not just ignore it.
			if (stack->isStackEmpty()) {					// before popping, check if stack is empty, if it is we have an invalid expression.
				std::cerr << "Invalid Expression! X Pop failed" << std::endl;
				return -99;
			}
			x = stack->pop();								// pop first value.
			if (stack->isStackEmpty()) {					
				std::cerr << "Invalid Expression! Y Pop failed" << std::endl;
				return -99;
			}
			y = stack->pop();								// pop second value.

			switch (c) {									// determine which operand c represents and apply the appropriate mathematical function.
			case '+':
				stack->push(y + x);	
				break;

			case '-':
				stack->push(y - x);							
				break;

			case '*':
				stack->push(y * x);	
				break;

			case '/':
				stack->push(y / x);							
				break;

			case '^':
				if (x == 0) {								
					stack->push(1);
					break;
				}

				z = y;										// z will hold the resultz
				for (int j = 1; j < x; j++) {				// loop from 1 to exponent, multiplying y by the previous result to simulation exponential multiplication.
					z *= y;
				}
				stack->push(z);								// push z onto stack.
				break;

			case '%':
				stack->push(y % x);							// modulo the second element popped by the first.
				break;
			}
		}
	}

	return stack->peek();									// the result should be at the top of the stack.
}

bool isCharAnInteger(char c) {
	int x = (int)c;
	
	return ((x >= 48) && (x <= 57));						// return true if character is in the range of integers on the ASCII table.
}

bool isCharAnOperand(char c) {
	switch (c) {
	default:
		return false;
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '%':
		return true;
	}
}