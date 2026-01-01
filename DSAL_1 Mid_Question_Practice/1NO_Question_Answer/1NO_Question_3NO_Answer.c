#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *head = NULL;

/* Insert node at end */
void insert(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Create a cycle (last node points to position pos, 1-based index) */
void createCycle(int pos) {
    if (pos == 0) return;

    struct node *temp = head;
    struct node *cycleNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = cycleNode;
}

/* Detect cycle using Floyd’s Algorithm */
int detectCycle() {
    struct node *slow = head;
    struct node *first = head;

    while(first != NULL && first -> next != NULL){
        slow = slow -> next;
        first = first -> next -> next;


        if(slow == first){
            return 1;
        }
    }

    return 0;
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    /* Create cycle: last node points to node 3 */
    createCycle(3);

    if (detectCycle()) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle in the linked list.\n");
    }

    return 0;
}
