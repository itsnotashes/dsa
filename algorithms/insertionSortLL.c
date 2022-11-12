// Given the head pointer of a linked list, sort it using insertion sort algorithm.

#include <stdio.h>
#include <stdlib.h>

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

void printlist(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

// Sort a linked list using insertion sort algorithm given the head pointer
void insertion_sort(struct Node *head) {
    for(struct Node* temp_i = head; temp_i != NULL; temp_i = temp_i->next) {
        for (struct Node* temp_j = head; temp_j != temp_i; temp_j = temp_j->next) {
            if (temp_i->val < temp_j->val) {
                int temp = temp_i->val;
                temp_i->val = temp_j->val;
                temp_j->val = temp;
            }
        }
    }
}

int main(){
    insert(5);
    insert(4);
    insert(8);
    insert(2);
    insert(7);
    printlist();
    printf("\n");
    insertion_sort(head);
    printlist();
    printf("\n");
    return 0;
}
