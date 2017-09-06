//
//  Gen_TreeCvtBin_Tree.c
//  Algorithm_study_group
//
//  Created by LSH on 2017. 9. 6..
//  Copyright © 2017년 LSH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


// struct Binary tree
typedef struct BTreeNode *Btree_Ptr;
typedef struct BTreeNode {
    int key;
    Btree_Ptr leftchild, rightchild;
}Binarytree;

// struct General tree
typedef struct GTreeNode *Gtree_Ptr;
typedef struct GTreeNode {
    int tree_level;
    int key;
    int child_key;
}Generaltree;


int Convert(Btree_Ptr *, int);
void Search(Btree_Ptr *, Btree_Ptr, int);
void visit(Btree_Ptr);
void BinaryFree(Btree_Ptr );
void Left();
void Right();
Btree_Ptr CreateNode(Btree_Ptr, int);
Btree_Ptr Location_ptr = NULL;
Gtree_Ptr Input;


void main() {
    
    Btree_Ptr root = NULL;
    int level, key, child_key;
    int choice;
    int curr_level = -1;
    
    while (1){
        printf("=====================================\n");
        printf("[1] Read and Convert to Binary tree\n");
        printf("[2] Print \n");
        printf("[3] Exit \n  : ");
        scanf_s("%d", &choice);
        
        if (choice == 1){
            Input = (Gtree_Ptr)malloc(sizeof(Generaltree));
            printf("Enter the tree [Level], [Key], [Child key(if none enter 0)] :  ");
            scanf_s("%d %d %d", &level, &key, &child_key);
            Input->tree_level = level, Input->key = key, Input->child_key = child_key;
            curr_level = Convert(&root, curr_level);
            free(Input);  // deallocation data node
        }
        else if (choice == 2){
            visit(root);
        }
        else if (choice == 3){
            BinaryFree(root);  // deallocation binary tree
            break;
        }
        else
            printf("Error!");
    }
}


/* description : convert a general tree to a binary tree by LCRS
 input : data current tree level
 output : data new current tree level
 */
int Convert(Btree_Ptr *root, int curr_level) {
    
    Btree_Ptr newNode = NULL;
    Btree_Ptr tmp = NULL;
    
    /* if root node does not exist */
    if (*root == NULL){
        *root = CreateNode(newNode, Input->key);
        
        /* if root node has child */
        if (Input->child_key)
            (*root)->leftchild = CreateNode(newNode, Input->child_key);  // create a left child node
    }
    
    /* if root node exist */
    else{
        Search(&tmp, *root, Input->key);
        /* if search key does not exist */
        if ((tmp == NULL)&&(curr_level == Input->tree_level)){
            Right();
        }
        
        /* if search key exist */
        else{
            Location_ptr = tmp;
            curr_level = Input->tree_level;
            Left();
        }
    }
    return curr_level;
}


/* description : case of new node is left child
 input : none
 output : none
 */
void Left() {
    Btree_Ptr newNode = NULL;
    
    if (Input->child_key)
        Location_ptr->leftchild = CreateNode(newNode, Input->child_key);  // create a left child node
}


/* description : case of new node is right sibling
 input : none
 output : none
 */
void Right() {
    Btree_Ptr newNode = NULL;
    
    if (Input->child_key){
        Location_ptr->rightchild = CreateNode(newNode, Input->key);
        Location_ptr = Location_ptr->rightchild;
        Location_ptr->leftchild = CreateNode(newNode, Input->child_key);  // create a left child node
    }
    else{
        Location_ptr->rightchild = CreateNode(newNode, Input->key);
        Location_ptr = Location_ptr->rightchild;
    }
}


/* description : create a new node
 input : data node pointer, insert key
 output : data new node pointer
 */
Btree_Ptr CreateNode(Btree_Ptr newNode, int insert_key) {
    newNode = (Btree_Ptr)malloc(sizeof(Binarytree));
    newNode->key = insert_key;
    newNode->leftchild = newNode->rightchild = NULL;
    return newNode;
}


/* description : search the key. if key found update the temporary pointer to that node's pointer
 input : data temporary location pointer, root node pointer, search key
 output : none
 */
void Search(Btree_Ptr *tmp, Btree_Ptr root, int search_key) {
    if (root){
        if (search_key == root->key)
            *tmp = root;
        Search(tmp, root->leftchild, search_key);
        Search(tmp, root->rightchild, search_key);
    }
}


/* description : traversal by preorder
 input : data root node pointer
 output : none
 */
void visit(Btree_Ptr root) {
    if (root){
        printf("   [ %d ]   \n", root->key);
        visit(root->leftchild);
        visit(root->rightchild);
    }
}


/* description : deallocation(free) binary tree
 input : data root node pointer
 output : none
 */
void BinaryFree(Btree_Ptr root) {
    if (root != NULL) {
        BinaryFree(root->leftchild);
        BinaryFree(root->rightchild);
        free(root);
    }
}
