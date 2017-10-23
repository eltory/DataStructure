//
//  링크드리스트.cpp
//  Algorithm_study_group
//
//  Created by LSH on 2017. 10. 21..
//  Copyright © 2017년 LSH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node* nptr;
typedef struct node{
    int key;
    nptr next;
    nptr prev;
}node;

nptr isFull();
bool isEmpty();
void insertNode(int);
void deleteNode(int);
nptr createNode(int);
nptr findLocation();
void link(nptr, nptr);
void print();
void printReverse();
void sort(int, nptr, nptr);
int getSize( );

void quickSort(nptr, nptr);
nptr partition(nptr, nptr);
void mergeSort(nptr, nptr);
void swap(nptr, nptr);

nptr head = NULL;
nptr tail = NULL;
int size = 0;

int main(){

    head = createNode(0);
    tail = createNode(0);
    link(head, tail);

    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);
    sort(1, head->next, tail->prev);
    deleteNode(1);
    print();
    printf("%d",size);
    return 0;
}

nptr isFull(){
    return (nptr)malloc(sizeof(node));
}

bool isEmpty(){
    return head->next == tail;
}

/* Create a node with the key value */
nptr createNode(int key){
    nptr new_node = isFull();
    if(new_node == NULL){
        printf("memory alloction is failed!");
        return NULL;
    }
    new_node->key = key;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

/* Insert a node into the linked list */
void insertNode(int key){
    nptr prev_node = NULL;
    nptr next_node = NULL;
    nptr new_node = createNode(key);

    prev_node = findLocation();
    next_node = prev_node->next;
    link(prev_node, new_node);
    link(new_node, next_node);
    size++;
}

void deleteNode(int key){
    nptr curr_node = head->next;

    if(isEmpty()){
        printf("A Linked list is already empty!");
        return;
    }
    while(curr_node){
        if(curr_node->key == key){
            link(curr_node->prev, curr_node->next);
            free(curr_node);
        }curr_node = curr_node->next;
    }
    size--;
}

/* Link a node with the prev and next node */
void link(nptr prev_node, nptr next_node){
    prev_node->next = next_node;

    if(next_node != NULL)
        next_node->prev = prev_node;
}

/* Find the location which to be inserted */
nptr findLocation(){
    return tail->prev;
}

/* Print values from the head to tail */
void print(){
    nptr curr_node = head->next;

    while(curr_node != tail){
        printf("%d ",curr_node->key);
        curr_node = curr_node->next;
    }
}

/* Print values from the tail to head */
void printReverse(){
    nptr curr_node = tail->prev;

    while(curr_node != head){
        printf("%d\n",curr_node->key);
        curr_node = curr_node->prev;
    }
}

/* Sort by kinds of sorts */
void sort(int selection, nptr start, nptr end){
    if(selection == 1)
        quickSort(start, end);
    else if(selection == 2)
        ; //mergeSort(start, end);
}

/* Use quick sort */
void quickSort(nptr start, nptr end){
    nptr pivot = head->next;

    if(end == start->prev || start == end->next)
        return;
    if(start != end){
        pivot = partition(start, end);
        quickSort(start, pivot->prev);
        quickSort(pivot->next, end);
    }
}

/* quick sort partition */
nptr partition(nptr start, nptr end){
    nptr pivot = end;
    nptr left = start, right = end;

    while(left != right){
        while((left->key < pivot->key) && (left != right))
            left = left->next;
        while((right->key >= pivot->key) && (left != right))
            right = right->prev;
        if(left != right)
            swap(left, right);
    }
    swap(pivot, right);
    return right;
}

/* Use merge sort */
void mergeSort(nptr start, nptr end){
    
}

void swap(nptr a, nptr b){
    int tmp;

    tmp = a->key;
    a->key = b->key;
    b->key = tmp;
}




