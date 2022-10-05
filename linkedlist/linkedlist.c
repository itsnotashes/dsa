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

void print(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

// The following function traverses half of the linked list in one go. 
void print_half(){
    Node *tortoise = head;
    Node *hare = head;

    printf("\nHalf of the linkedlist: ");
    while(hare != NULL && hare->next !=NULL){
        printf("%d ", tortoise->val);
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
}

// The folling function detects loops in the linkedlist
void loop_detection(){
    Node *tortoise = head;
    Node *hare = head;

    while (hare != NULL && hare->next !=NULL){
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare){
            printf("\nThe linkedlist has a loop.");
            exit(0);
        }
    }
    printf("\nThere are no loops in this linkedlist.\n");
}

void reverse_list(){
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void main(){
    insert(5);
    insert(6);
    insert(7);
    insert(78);
    insert(69);
    insert(87);
    insert(8);
    insert(8);
    print();
    print_half();
    loop_detection();
    reverse_list();
    print();
    reverse_k_nodes(2);
    print();
}