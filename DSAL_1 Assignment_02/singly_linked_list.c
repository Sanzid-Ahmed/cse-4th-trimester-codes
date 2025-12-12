#include <stdio.h>
#include <stdlib.h>


//cell
struct node{
    int value;
    struct node *next;
};


//manager
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

    struct node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    newNode -> next = NULL;
    temp -> next = newNode;
}

//insert value after a targeted number.
void insertAny(int num, int value){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));

    newNode -> value = value;

    struct node *temp = head;
    while(temp -> value != num){
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;
}


//insert in a target index
void insertAnyIndex(int num, int value){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));

    newNode -> value = value;

    struct node *temp = head;
    int index = 0;
    while(index != num){
            if(temp == NULL){
                printf("Invalid Index");
                return;
            }
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;
}


void deleteFirst(){
    if(head == NULL){
        printf("List is already empty!\n");
        return;
    }

    struct node *temp = head;
    head = head -> next;
    free(temp);
}

void deleteLast(){
    if(head == NULL){
        printf("List is already empty!\n");
        return;
    }


    if(head -> next == NULL){
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head, *preTemp = head;

    while(temp -> next != NULL){
        preTemp = temp;
        temp = temp -> next;
    }

    preTemp -> next = NULL;
    free(temp);
}

void deleteAny(int value){
    struct node *temp = head, *preTemp = head;



    while(temp -> value != value){
        if(temp -> next == NULL){
            printf("The number does not exist!");
            return;
        }

        preTemp = temp;
        temp = temp -> next;
    }

    preTemp -> next = temp -> next;
    free(temp);
}


void reverseList(){
    struct node *previous = NULL, *current = head, *next = NULL;

    while(current != NULL){
        next = current -> next;
        current -> next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

void findMiddle(){
    if(head == NULL) return;
    struct node *mid = head, *control = head;

    while(mid != NULL && control->next != NULL){
        mid = mid -> next;
        control = control -> next -> next;
    }

    printf("%d", mid -> value);
}

void rotateList(int k){
    if(head == NULL || k == 0){
        return;
    }

    struct node *temp = head;
    int length = 0;

    while(temp -> next != NULL){
        temp = temp -> next;
        length++;
    }

    temp -> next = head;

    k = k % length;

    struct node *control = head;
    for(int i = 0; i < k; i++){
        control = control -> next;
    }

    head = control -> next;
    control -> next = NULL;
}

int findNthFromLast(int N){
    struct node *temp = head;
    int length = 1;

    while(temp -> next != NULL){
        length++;
        temp = temp -> next;
        //length++; this will count -1 times
    }

    if(N > length){
        return -1;
    }

    int position = length - N;
    temp = head;

    for(int i = 0; i < position; i++){
        temp = temp -> next;
    }

    return temp -> value;
}


void detectCycle(){
    struct node *first = head, *second = head;

    while(first != NULL && second != NULL){
        first = first -> next;
        second = second -> next -> next;

        if(first == second){
            printf("Cycle detected!\n");
            return;
        }
    }

    printf("No cycle found.\n");
}

void bubbleSort() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    int swapped;

    struct node *ptr;
    struct node *last = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->value > ptr->next->value) {

                int temp = ptr->value;
                ptr->value = ptr->next->value;
                ptr->next->value = temp;

                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

void printList() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


int main() {

    insertFirst(30);
    insertFirst(20);
    insertFirst(10);

    printf("After insertFirst:\n");
    printList();

    insertLast(40);
    insertLast(50);
    printf("After insertLast:\n");
    printList();

    insertAny(30, 35); // insert 35 after value=30
    printf("After insertAny:\n");
    printList();

    deleteFirst();
    printf("After deleteFirst:\n");
    printList();

    deleteLast();
    printf("After deleteLast:\n");
    printList();

    deleteAny(35);
    printf("After deleteAny:\n");
    printList();

    reverseList();
    printf("After reverseList:\n");
    printList();

    printf("Middle element:\n");
    findMiddle();

    printf("\nRotate by k=2:\n");
    rotateList(2);
    printList();

    printf("3rd from last: %d\n", findNthFromLast(3));

    bubbleSort();
    printf("After sorting:\n");
    printList();

    return 0;
}

