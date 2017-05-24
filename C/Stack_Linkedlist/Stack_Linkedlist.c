#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct node* nptr;
typedef struct node {
	int key;
	nptr next;
}Node;

nptr isEmpty();
nptr isFull();
nptr createNode();
int push(nptr, int);
int pop();
void display();
void reset();
void freeStackNode();

nptr top = NULL;
nptr STACK = NULL;

int main() {

	int selNum;
	int data;
	nptr tmp;

	STACK = createNode();
	top = STACK->next;

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
			tmp = isFull();
			if (tmp == NULL) {
				printf("\n The stack is already full.\n");
			}
			else {
				printf("\n Enter the data you want to push into stack : ");
				scanf(" %d", &data);
				push(tmp, data);
			}
			break;
		case 2:
			if (isEmpty() == NULL) {
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

nptr createNode() {
	nptr tmpNode = NULL;
	tmpNode = (nptr)malloc(sizeof(Node));
	tmpNode->next = NULL;

	return tmpNode;
}

nptr isFull() {
	return createNode();
}

nptr isEmpty() {
	return top;
}

int push(nptr node, int data) {
	nptr tmp = STACK->next;

	if (tmp == NULL) {
		STACK->next = node;
		node->key = data;
		top = node;

		return 0;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = node;
	node->key = data;
	top = node;

	return 0;
}

int pop() {
	nptr prev = STACK->next;
	nptr tmp = prev->next;

	if (tmp == NULL) {
		STACK->next = NULL;
		top = STACK->next;
		free(prev);

		return 0;
	}
	while (tmp->next != NULL) {
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	top = prev;
	free(tmp);

	return 0;
}

void freeStackNode() {
	nptr prev = STACK->next;
	nptr tmp = prev->next;

	if (tmp == NULL) {
		free(prev);
	}
	while (tmp != NULL) {
		free(prev);
		prev = tmp;
		tmp = tmp->next;
	}
	STACK->next = NULL;
	top = STACK->next;
}

void display() {
	nptr tmp = STACK->next;

	if (isEmpty() == NULL) {
		printf("\n The stack is empty.\n");
		return;
	}
	printf("\n [ STACK ]");
	printf("\n ---------");

	while (tmp != NULL) {
		printf("\n | %d ", tmp->key);
		tmp = tmp->next;
	}
}

void reset() {
	if (isEmpty() != NULL)
		freeStackNode();
}