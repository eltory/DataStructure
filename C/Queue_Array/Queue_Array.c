#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SIZE 100

int front = -1, rear = -1;
int QUEUE[SIZE];

int isEmpty();
int isFull();
int insert(int);
int delete();
void display();
void reset();

int main() {

	int selNum;
	int data;

	while (1) {
		printf("\n Select number ");
		printf("\n ------------- ");
		printf("\n 1. insert");
		printf("\n 2. delete");
		printf("\n 3. display");
		printf("\n 4. reset");
		printf("\n 5. exit\n");

		scanf(" %d", &selNum);
		switch (selNum) {
		case 1:
			if (isFull()) {
				printf("\n The queue is already full.\n");
			}
			else {
				printf("\n Enter the data you want to insert into queue : ");
				scanf(" %d", &data);
				insert(data);
			}
			break;
		case 2:
			if (isEmpty()) {
				printf("\n The queue is already empty.\n");
			}
			else {
				delete();
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
	if (rear == SIZE - 1)
		return 1;
	return 0;
}

int isEmpty() {
	if (front == rear)
		return 1;
	return 0;
}

int insert(int data) {
	QUEUE[++rear] = data;
	return 0;
}

int delete() {
	front++;
	return 0;
}

void display() {
	int i;

	if (isEmpty()) {
		printf("\n The queue is empty.\n");
		return;
	}
	printf("\n [ QUEUE ]");
	printf("\n ---------");

	for (i = front + 1; i <= rear; ++i) {
		printf("\n | %d ", QUEUE[i]);
	}
}

void reset() {
	front = rear = -1;
}