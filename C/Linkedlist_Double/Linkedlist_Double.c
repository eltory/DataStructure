#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node* nptr;
typedef struct node {
	int key;
	nptr prev;
	nptr next;
}Node;


nptr head = NULL;
nptr tail = NULL;

nptr createNode(int);
void Insert(int);
void Delete(int);
nptr Search(int);
void print();
void reversePrint();

int main() {

	int selNum;
	int key;
	nptr tmp = NULL;

	// make a head
	head = createNode(NULL);
	tail = createNode(NULL);

	while (1) {
		printf("\n Select number ");
		printf("\n ------------- ");
		printf("\n 1. insert");
		printf("\n 2. delete");
		printf("\n 3. display");
		printf("\n 4. reversely display");
		printf("\n 5. search");
		printf("\n 6. exit\n");

		scanf(" %d", &selNum);

		switch (selNum) {
		case 1:
			printf("\n Enter the data you want to insert : ");
			scanf(" %d", &key);

			Insert(key);
			break;
		case 2:
			printf("\n Enter the data you want to delete : ");
			scanf(" %d", &key);

			if (Search(key) == NULL)
				printf("\n The data does not exist");
			else
				Delete(key);
			break;
		case 3:
			print();
			break;
		case 4:
			reversePrint();
			break;
		case 5:
			printf("\n Enter the data you want to search : ");
			scanf(" %d", &key);

			if (Search(key) == NULL)
				printf("\n The data is not exist");
			else
				printf("\n The data can be found");
			break;
		default:
			printf("\n select between number 1 to 5 \n");
			exit(0);
			break;
		}
	}

	return 0;
}

nptr createNode(int key) {
	nptr tmp = NULL;

	tmp = (nptr)malloc(sizeof(Node));
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->key = key;

	return tmp;
}

void Insert(int key) {
	nptr tmp = head;
	nptr node = createNode(key);

	if (node == NULL)
		return;

	while (tmp->next != NULL && tmp->next != tail) {
		tmp = tmp->next;
	}
	tmp->next = node;
	node->prev = tmp;
	node->next = tail;
	tail->prev = node;
}

void Delete(int key) {
	nptr tmp = head;
	nptr find = tmp->next;

	// delete all duplicated data
	while (tmp->next != NULL) {
		find = tmp->next;
		if (find->key == key) {
			tmp->next = find->next;
			find->next->prev = tmp;
			free(find);
		}
		else
			tmp = tmp->next;
	}
}

nptr Search(int key) {
	nptr tmp = head->next;

	if (tmp == NULL)
		return;

	while (tmp != tail) {
		if (tmp->key == key)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

void print() {
	nptr tmp = head->next;

	if (tmp == NULL || tmp == tail) {
		printf("\n Empty linked list");
		return;
	}
	while (tmp != tail) {
		printf("[ %d ]\n", tmp->key);
		tmp = tmp->next;
	}
}

void reversePrint() {
	nptr tmp = tail->prev;

	if (tmp == NULL || tmp == head) {
		printf("\n Empty linked list");
		return;
	}
	while (tmp != head) {
		printf("[ %d ]\n", tmp->key);
		tmp = tmp->prev;
	}
}