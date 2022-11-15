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

// Write a helper partition function that takes the head pointer and returns the new head pointer
struct Node* partition(struct Node* head, struct Node* tail) {

    struct Node* pivot = head;
    struct Node* temp = head;

    int tempData;

    while (temp != tail) {
        if (temp->val < tail->val) {
            pivot = head;

            tempData = temp->val;
            temp->val = pivot->val;
            pivot->val = tempData;

            head = head->next;
        }
        temp = temp->next;
        
    }
    tempData = head->val;
    head->val = tail->val;
    tail->val = tempData;
    return pivot;
    
}

// Write a helper quick_sort_recur function that takes the head pointer and returns the new head pointer
void quick_sort(struct Node* head, struct Node* tail) {
    if (head == tail) {
        return;
    }
    struct Node* pivot = partition(head, tail);
 
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, tail);
    }
 
    if (pivot != NULL && head != pivot) {
        quick_sort(head, pivot);
    }
}


int main(){
    insert(5);
    insert(4);
    insert(8);
    insert(2);
    insert(7);
    printlist();
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    quick_sort(head, tail);
    printf("\n");
    printlist();
}