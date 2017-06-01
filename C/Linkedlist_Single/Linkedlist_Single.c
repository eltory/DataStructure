#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node* nptr;
typedef struct node {
	int key;
	nptr next;
}Node;

nptr head = NULL;

nptr createNode(int);
void Insert(int);
void Delete(int);
nptr Search(int);
void print();

int main() {

	int selNum;
	int key;

	// make a head
	head = createNode(NULL);

	while (1) {
		printf("\n Select number ");
		printf("\n ------------- ");
		printf("\n 1. insert");
		printf("\n 2. delete");
		printf("\n 3. display");
		printf("\n 4. search");
		printf("\n 5. exit\n");

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
			printf("\n Enter the data you want to search : ");
			scanf(" %d", &key);

			if (Search(key) == NULL)
				printf("\n The data does not exist");
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
	tmp->next = NULL;
	tmp->key = key;

	return tmp;
}

void Insert(int key) {
	nptr tmp = head;
	nptr node = createNode(key);

	if (node == NULL)
		return;

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = node;
}

void Delete(int key) {
	nptr tmp = head;
	nptr find = tmp->next;

	// delete all duplicated data
	while (tmp->next != NULL) {
		find = tmp->next;
		if (find->key == key) {
			tmp->next = find->next;
			free(find);
		}else
			tmp = tmp->next;
	}
}

nptr Search(int key) {
	nptr tmp = head->next;

	while (tmp != NULL) {
		if (tmp->key == key)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

void print() {
	nptr tmp = head->next;

	if (tmp == NULL) {
		printf("\n Empty linked list");
		return;
	}
	while (tmp != NULL) {
		printf("[ %d ]\n", tmp->key);
		tmp = tmp->next;
	}
}