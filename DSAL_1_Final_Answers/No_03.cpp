#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node *left, *right, *parent;
};

Node *root=NULL;

void Insert(int val) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL) {
        newNode->parent = NULL;
        root = newNode;
    }
    else {
        Node *temp = root;
        while(1) {
            if(temp->value > val) { // null
                // left
                if(temp->left == NULL) {
                    break;
                }
                temp = temp->left;
            }
            else {
                // right
                if(temp->right == NULL) {
                    break;
                }
                temp = temp->right;
            }
        }
        // temp->17
        if(temp->value > val) {
            // insert left
            temp->left = newNode;
            newNode->parent = temp;
        }
        else {
            // insert right
            temp->right = newNode;
            newNode->parent = temp;
        }
    }
}

void inOrder(Node *root){
    if(root == NULL){
        return;
    }


    inOrder(root -> left);
    printf("%d ", root -> value);
    inOrder(root -> right);
}


Node* pre(Node *a){
    while(a -> left != NULL){
        a = a -> left;
    }

    return a;
}
/*
Node* deleteID(Node *root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root -> value){
        inOrder(root -> left);
    }
    else if(key < root -> value){
        inOrder(root -> right);
    }
    else{
        if(root -> left == NULL && root -> right == NULL){
            free(root);
            return NULL;
        }
        else if(root -> left == NULL){
            Node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            Node *temp = root -> left;
            free(root);
            return temp;
        }
        else{
            Node* temp = pre(root -> right);
            root -> value = temp -> value;
            deleteID(root, temp -> value;
        }
    }

    return root;
}
*/

int main() {
    int Q;
    scanf("%d", &Q);

    for(int i = 0; i < Q; i++){
        int x;
        scanf("%d", &x);

        if(x == 1){
            int id;
            scanf("%d", &id);
            Insert(id);
        }
        /*
        else if(x == 2){
                int v;
        scanf("%d", &v);
            deleteID(root, v);
        }*/
        else if(x == 3){
            inOrder(root);
        }
    }
}
