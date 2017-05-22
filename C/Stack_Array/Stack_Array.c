#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100

int top = -1;
int STACK[SIZE];

int isEmpty();
int isFull();
int push(int);
int pop();
void display();
void reset();

int main() {

	int selNum;
	int data;

	while (1) {
		printf("\n Select number ");
		printf("\n ------------- ");
		printf("\n 1. push");
		printf("\n 2. pop");
		printf("\n 3. display");
		printf("\n 4. reset");
		printf("\n 5. exit\n");

		scanf(" %d", &selNum);
			switch (selNum) {
			case 1:
				if (isFull()) {
					printf("\n The stack is already full.\n");
				}
				else {
					printf("\n Enter the data you want to push into stack : ");
					scanf(" %d", &data);
					push(data);
				}
				break;
			case 2:
				if (isEmpty()) {
					printf("\n The stack is already empty.\n");
				}
				else {
					pop();
				}
				break;
			case 3: display();
				break;
			case 4: reset();
				break;
			case 5: exit(0);
				break;
			default: printf("\n select between number 1 to 5 \n");
				break;
			}
		}
	return 0;
}

int isFull() {
	if (top == SIZE - 1)
		return 1;
	return 0;
}

int isEmpty() {
	if (top == -1)
		return 1;
	return 0;
}

int push(int data) {
	STACK[++top] = data;
	return 0;
}

int pop() {
	top--;
	return 0;
}

void display() {
	int i;

	if (isEmpty()) {
		printf("\n The stack is empty.\n");
		return;
	}
	printf("\n [ STACK ]");
	printf("\n ---------");

	for (i = 0; i <= top; ++i) {
		printf("\n | %d ", STACK[i]);
	}
}

void reset() {
	top = -1;
}