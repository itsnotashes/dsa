// Creating Binary Search Tree from a list of integers

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *root = NULL;

// Insert a node into the tree
void insert(int data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) {
        root = temp;
    } else {
        node *temp1 = root;
        while (1) {
            if (data < temp1->data) {
                if (temp1->left == NULL) {
                    temp1->left = temp;
                    break;
                } else {
                    temp1 = temp1->left;
                }
            } else {
                if (temp1->right == NULL) {
                    temp1->right = temp;
                    break;
                } else {
                    temp1 = temp1->right;
                }
            }
        }
    }
}


// Print the tree
void print(node *temp) {
    if (temp != NULL) {
        print(temp->left);
        printf("%d ", temp->data);
        print(temp->right);
    }
}

// Construct a binary search tree from an array of integers
void construct(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
}

// Delete a node from the tree
void delete(int data) {
    node *temp = root;
    node *parent = NULL;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->left == NULL && temp->right == NULL) {
                if (parent->left == temp) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                free(temp);
            } else if (temp->left == NULL) {
                if (parent->left == temp) {
                    parent->left = temp->right;
                } else {
                    parent->right = temp->right;
                }
                free(temp);
            } else if (temp->right == NULL) {
                if (parent->left == temp) {
                    parent->left = temp->left;
                } else {
                    parent->right = temp->left;
                }
                free(temp);
            } else {
                node *temp1 = temp->right;
                node *parent1 = temp;
                while (temp1->left != NULL) {
                    parent1 = temp1;
                    temp1 = temp1->left;
                }
                temp->data = temp1->data;
                if (parent1->left == temp1) {
                    parent1->left = temp1->right;
                } else {
                    parent1->right = temp1->right;
                }
                free(temp1);
            }
            break;
        } else if (data < temp->data) {
            parent = temp;
            temp = temp->left;
        } else {
            parent = temp;
            temp = temp->right;
        }
    }
}


void main() {
    int arr[] = { 5, 3, 7, 1, 4, 6, 8, 87, 49, 23, 12, 34, 56, 78, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    construct(arr, n);
    print(root);
    delete(5);
    printf("\n");
    print(root);
}