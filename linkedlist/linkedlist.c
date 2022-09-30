#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->val = data;
    temp->next = NULL;

    if (head == NULL){
        head = temp;
    } else {
        Node *head_travel = head;
        while (head_travel->next != NULL){
            head_travel = head_travel->next;
        }
        head_travel->next = temp;
    }
}

void main(){
    insert(5);
    insert(6);
    insert(7);
    Node *temp = head;
    while (temp != NULL){
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}