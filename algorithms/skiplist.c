#include <stdio.h>
#include <stdlib.h>

struct node{
int val;
struct node * next;
struct node * next5;
struct node * next10;
};

typedef struct node Node;


void print_skipped_list_(Node * head){
    Node * current = head;
    while(current!=NULL){
        if (current->next==NULL){
            printf("%d ",current->val);
        }
        else{
            printf("%d ",current->val);
        }
        current = current->next;
    }
    printf("\n");
}

//print linked list with next5
void print_skipped_list_5(Node * head){
    printf("%d ",head->val);
    Node * current = head;
    while(current!=NULL){
        if (current->next5!=NULL){
            printf("%d ",current->next->val);
        }
        current = current->next;
    }
    printf("\n");
}

void print_skipped_list_10(Node * head){
    printf("%d ",head->val);
    Node * current = head;
    while(current!=NULL){
        if (current->next10!=NULL){
            printf("%d ",current->next->val);
        }
        current = current->next;
    }
    printf("\n");
}

//convert an array to skip list
Node * arrayToSkipList(int * a, int n){
    Node * head = (Node *)malloc(sizeof(Node));
    head->val = a[0];
    head->next = NULL;
    head->next5 = NULL;
    head->next10 = NULL;

    Node * current = head;
    for(int i=1;i<n;i++){
        Node * new = (Node *)malloc(sizeof(Node));
        new->val = a[i];
        new->next = NULL;
        new->next5 = NULL;
        new->next10 = NULL;

        current->next = new;
        current = current->next;
    }

    current = head;
    int count = 0;
    while(current!=NULL){
        count++;
        if (count%5==0){
            current->next5 = current->next;
        }
        if (count%10==0){
            current->next10 = current->next;
        }
        current = current->next;
    }

    return head;
}

int main( ){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int n = sizeof(a)/sizeof(a[0]);

    Node * head = arrayToSkipList(a,n);
    printf("Normal Linked List: ");
    print_skipped_list_(head);
    printf("Linked List with 5 skips: ");
    print_skipped_list_5(head);
    printf("Linked List with 10 skips: ");
    print_skipped_list_10(head);

    return 0;
}