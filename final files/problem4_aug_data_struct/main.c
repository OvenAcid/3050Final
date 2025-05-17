#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

struct ListInfo{
    Node * head;
    Node * tail;
    int size; // gets updated with each add and delete.
    int empty; // if 0 list is not empty. if 1 list is empty.

};

typedef struct list{
    struct ListInfo * info;
}list;

list makeList(){

    list p;
    p.info = malloc(sizeof(struct ListInfo));

    if (p.info == NULL){
        return p;
    }

    p.info->head = NULL;
    p.info->tail = NULL;
    p.info->size = 0;
    p.info->empty = 1;

    return p;
}

//get size
int getSize(list p){

    return(p.info->size);

}

// just gets index number

int getIndex(list p, int value){
    Node * x = p.info->head;

    int index = 0;

    while(index != getSize(p)){
        if (x->data == value){
            return index;
        }
        ++index;
        x = x->next;
    }

    return -1;
}

Node * getAtIndex(list p, int value){
    Node * x = p.info->head;

    while(x != NULL){
        if (x->data == value){
            return x;
        }
        x = x->next;
    }

    return NULL;
}

//check empty
void checkIfEmpty(list p){

    if(p.info->empty == 0){
        printf("\nlist is not empty.\n");
    }
    else{
        printf("\nlist is empty.\n");
    }

}

//delete node
int removeAtIndex(list list, int index, int *success){ // in the future test for removing all starting at head
    
    
    int size = getSize(list);
    if (index < 0 || index > size || size == 0){
        *success = 0;
        return 0;
    }

    Node * p = list.info->head;

    int count = 0;
    int value = 0;

    if(index == 0){
        value = p->data;
        list.info->head = p->next;
        if (list.info->head == NULL) {  
            list.info->tail = NULL;  
        }
        free(p);
        *success = 1;
        return value;
    }


    while (count < index-1){ // finding node before
        p = p->next;
        count++;
    }

    Node * temp = p->next;
    p->next = temp->next;

    if (temp->next == NULL) {
        list.info->tail = p;
    }
    
    value = temp->data;

    free(temp);
    *success = 1;
    return value;

}

int deleteNode(list p, int value){

    int index = getIndex(p,value);
    
    if(index == -1 ){
        return 0;
    }

    int ec = 0;

    removeAtIndex(p, index, &ec);

    if(ec == 1){
        (p.info->size)--;
        if(p.info->size == 0){
            p.info->empty = 1;
        }
        return 1;
    }
    else{
        return 0;
    }

}

//insert at end
void insertAtEnd (list p, int data){
    Node * new = malloc(sizeof(Node));

    if(new == NULL){
        return;
    }

    new->data = data;
    new->next = NULL;

    if(p.info->head == NULL){
        p.info->head = new;
        p.info->tail = new;
    }
    else{
        p.info->tail->next = new;
        p.info->tail = new;
    }

    (p.info->size)++;
    p.info->empty = 0;


}

Node* mergeAscending(Node* left, Node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    if (left->data <= right->data) {
        left->next = mergeAscending(left->next, right);
        return left;
    } else {
        right->next = mergeAscending(left, right->next);
        return right;
    }
}

// Merge (descending)
Node* mergeDescending(Node* left, Node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    if (left->data >= right->data) {
        left->next = mergeDescending(left->next, right);
        return left;
    } else {
        right->next = mergeDescending(left, right->next);
        return right;
    }
}

// Split function to divide list
void splitList(Node* head, Node** left, Node** right) {
    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    *left = head;
    *right = slow;
    if (prev != NULL) {
        prev->next = NULL;
    }
}

// Merge Sort for ascending 
void mergeSortAscending(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* left = NULL;
    Node* right = NULL;

    splitList(*head, &left, &right);

    mergeSortAscending(&left);
    mergeSortAscending(&right);

    *head = mergeAscending(left, right);
}

// Merge Sort for descending 
void mergeSortDescending(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* left = NULL;
    Node* right = NULL;

    splitList(*head, &left, &right);

    mergeSortDescending(&left);
    mergeSortDescending(&right);

    *head = mergeDescending(left, right);
}

// Sort ascending
void sortAscending(list p) {
    mergeSortAscending(&(p.info->head));
}

// Sort descending 
void sortDescending(list p) {
    mergeSortDescending(&(p.info->head));
}

//max integer

int maxInt(list p){

    if(p.info->empty){
        return -1;
    }

    Node * x = p.info->head;

    int max = x->data;

    while(x != NULL){
        if (x->data > max){
            max = x->data;
        }

        x = x->next;
    }

    return max;
}


//print function

void printList(list p){

    Node * x = p.info->head;

    while(x != NULL){
        printf("\n%d\n", x->data);
        x = x->next;
    }
}

void freeList(list p){ 


    Node * x = p.info->head;
    Node * temp;

    while(x != NULL){
        temp = x-> next;
        free(x);
        x = temp;
    }

    free(p.info);

    p.info = NULL;

}


int main() {
    // Agument Data Structure
    // Problem 4: Implement a data structure that can store a list of integers
    // and supports the following operations:

    list list = makeList();

    insertAtEnd(list, 10);
    insertAtEnd(list, 45);
    insertAtEnd(list, 2);
    insertAtEnd(list, 30);

    printList(list);

    printf("\n%d --",maxInt(list));

    sortAscending(list);
    printList(list);

    sortDescending(list);
    printList(list);

    deleteNode(list, 45);

    Node * x = getAtIndex(list, 10);

    printf("\n%d --- \n", x->data);


    printList(list);

    printf("\n- %d -", getSize(list));

    checkIfEmpty(list);

    

    freeList(list);

    // 1. Insert an integer at the end of the list
    // 2. Remove an integer from the list
    // 3. Get the integer at a specific index in the list
    // 4. Get the size of the list
    // 5. Check if the list is empty
    // 6. Clear the list
    // 7. Print the list
    // 8. Sort the list in ascending order
    // 9. Sort the list in descending order
    // 10. Find the maximum integer in the list     
    // TODO: Implement this problem's solution
    return 0;
}
