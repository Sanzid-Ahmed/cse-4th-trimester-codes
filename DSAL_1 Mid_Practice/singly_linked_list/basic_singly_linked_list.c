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
    if(head == NULL){
        newNode -> next = NULL;
        head = newNode;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }
}


void insertLast(int value){
    if(head == NULL){
        insertFirst(value);
        return;
    }

    struct node *newNode;
    newNode = malloc(sizeof(struct node));

    newNode -> value = value;
    newNode -> next = NULL;

    struct node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;
}





void insertAny(int num, int value){
    if(head == NULL){
        printf("The %d position is not valid", num);
        return;
    }

    struct node *temp = head;
    int count = 1;
    while(count != num){
        temp = temp -> next;
        count++;
    }

    struct node *newNode = malloc(sizeof(struct node));
    newNode -> next = temp -> next;
    newNode -> value = value;
    temp -> next = newNode;
}



void print(){
    struct node *temp = head;

    while(temp != NULL){
        printf("%d ", temp -> value);
        temp = temp -> next;
    }

    printf("\n");
}



int main(){


    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    print();
    insertLast(5);
    insertLast(4);
    print();
    insertAny(2, 15);
    print();


    return 0;
}
