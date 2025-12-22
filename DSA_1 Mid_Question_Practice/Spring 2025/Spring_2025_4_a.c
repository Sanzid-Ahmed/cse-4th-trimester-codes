#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

struct node *head = NULL;

void insertFirst(int value){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode -> value = value;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }
}

void print(){
    if(head == NULL){
        printf("The linked list is empty!!");
        return;
    }

    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp -> value);
        temp = temp -> next;
    }

    printf("\n");
}


void deleteAny(int value){
    struct node *temp = head;
    struct node *before = head;

    while(temp -> value != value){
        before = temp;
        temp = temp -> next;
    }

    before -> next = temp -> next;
    free(temp);
}


void insertNext(int value, int num){
    struct node *temp = head;

    while(temp -> value != num){
        temp = temp -> next;
    }

    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode -> value = value;

    newNode -> next = temp -> next;
    temp -> next = newNode;
}


int main(){
    insertFirst(29);
    insertFirst(12);
    insertFirst(47);
    insertFirst(36);
    insertFirst(25);

    print();

    deleteAny(47);


    print();

    insertNext(68, 36);
    print();

    return 0;
}
