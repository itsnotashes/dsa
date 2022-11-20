#include <stdio.h>
#include <stdlib.h>

// create an avl tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

node *root = NULL;

// get the height of a node
int height(node *temp) {
    if (temp == NULL) {
        return 0;
    } else {
        return temp->height;
    }
}

// get the maximum of two integers
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// get the balance factor of a node
int getBalance(node *temp) {
    if (temp == NULL) {
        return 0;
    } else {
        return height(temp->left) - height(temp->right);
    }
}

// right rotate a node
node *rightRotate(node *y) {
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// left rotate a node
node *leftRotate(node *x) {
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// insert a node into the tree
node *insert(node *temp, int data) {
    if (temp == NULL) {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        return temp;
    } else {
        if (data < temp->data) {
            temp->left = insert(temp->left, data);
        } else {
            temp->right = insert(temp->right, data);
        }
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        int balance = getBalance(temp);
        if (balance > 1 && data < temp->left->data) {
            return rightRotate(temp);
        }
        if (balance < -1 && data > temp->right->data) {
            return leftRotate(temp);
        }
        if (balance > 1 && data > temp->left->data) {
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }
        if (balance < -1 && data < temp->right->data) {
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }
        return temp;
    }
}

// print the tree
void print(node *temp) {
    if (temp != NULL) {
        print(temp->left);
        printf("%d ", temp->data);
        print(temp->right);
    }
}

// construct an avl tree from an array of integers
void construct(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
}

// search for a node in the tree
node *search(node *temp, int data) {
    if (temp == NULL) {
        return NULL;
    } else {
        if (data == temp->data) {
            return temp;
        } else {
            if (data < temp->data) {
                return search(temp->left, data);
            } else {
                return search(temp->right, data);
            }
        }
    }
}

// find the minimum value in the tree
node *minValueNode(node *temp) {
    node *current = temp;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

int main(){
    int arr[] = {1, 8, 3, 7, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    construct(arr, n);
    print(root);
    printf("\n");
    node *temp = search(root, 5);
    if (temp != NULL) {
        printf("Found %d", temp->data);
    } else {
        printf("Not found");
    }
    printf("\n");

    return 0;
}