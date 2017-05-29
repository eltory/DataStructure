#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct node* nptr;
typedef struct node {
	int key;
	nptr next;
}Node;

int isEmpty();
nptr isFull();
nptr createNode();
int insert(nptr, int);
int delete();
void display();
void reset();
void freeQueueNode();

nptr front = NULL;
nptr rear = NULL;
nptr QUEUE = NULL;

int main() {

	int selNum;
	int data;
	nptr tmp;

	QUEUE = createNode();

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
			tmp = isFull();
			if (tmp == NULL) {
				printf("\n The queue is already full.\n");
			}
			else {
				printf("\n Enter the data you want to insert into queue : ");
				scanf(" %d", &data);
				insert(tmp, data);
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

nptr createNode() {
	nptr tmpNode = NULL;
	tmpNode = (nptr)malloc(sizeof(Node));
	tmpNode->next = NULL;

	return tmpNode;
}

nptr isFull() {
	return createNode();
}

int isEmpty() {
	if (front == NULL)
		return 1;
	return 0;
}

int insert(nptr node, int data) {
	nptr tmp = front;

	if (tmp == NULL) {
		QUEUE->next = node;
		node->key = data;
		front = node;
		rear = front;

		return 0;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = node;
	node->key = data;
	rear = node;

	return 0;
}

int delete() {

	QUEUE->next = front->next;	
	free(front);
	front = QUEUE->next;

	return 0;
}

void freeQueueNode() {
	nptr prev = front;
	nptr tmp = prev->next;

	if (tmp == NULL) {
		free(prev);
	}
	while (tmp->next != NULL) {
		free(tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	QUEUE->next = NULL;
	front = rear = QUEUE->next;
}

void display() {
	nptr tmp = front;

	if (isEmpty()) {
		printf("\n The queue is empty.\n");
		return;
	}
	printf("\n [ QUEUE ]");
	printf("\n ---------");

	while (tmp != NULL) {
		printf("\n | %d ", tmp->key);
		tmp = tmp->next;
	}
}

void reset() {
	if (!isEmpty())
		freeQueueNode();
}