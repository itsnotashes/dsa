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

// Sort a linked list given the head pointer using selection sort
void selection_sort(struct Node *head){
    for (struct Node *temp_i = head; temp_i != NULL; temp_i = temp_i->next){
        struct Node *min = temp_i;
        for (struct Node *temp_j = temp_i->next; temp_j != NULL; temp_j = temp_j->next){
            if (temp_j->val < min->val){
                min = temp_j;
            }
        }
        int temp = temp_i->val;
        temp_i->val = min->val;
        min->val = temp;
    }
}


int main(){
    insert(5);
    insert(4);
    insert(8);
    insert(2);
    insert(7);
    printlist();
    selection_sort(head);
    printf("\n");
    printlist();
    return 0;
}