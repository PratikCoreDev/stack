#include<stdio.h>
#include<stdlib.h>

// Structure of Node
struct node{
    int data;
    struct node* next;
};

// Top pointer
struct node* top = NULL;

// Check if stack is empty
int isempty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}

// Check if stack is full
int isfull(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){
        return 1;
    }

    free(temp);
    return 0;
}

// Push element into stack
void push(int val){

    if(isfull()){
        printf("The stack is full, unable to insert %d\n", val);
    }
    else{
        struct node* newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = val;
        newnode->next = top;
        top = newnode;

        printf("Successfully inserted %d\n", val);
    }
}

// Pop element from stack
void pop(){

    if(isempty()){
        printf("The stack is empty, unable to pop\n");
    }
    else{
        struct node* temp = top;
        int val = temp->data;

        top = top->next;
        free(temp);

        printf("Successfully deleted %d\n", val);
    }
}

// Peek element
void peek(){

    if(isempty()){
        printf("The stack is empty\n");
    }
    else{
        printf("The peek element in the stack is: %d\n", top->data);
    }
}

// Display stack
void display(){

    if(isempty()){
        printf("The stack is empty\n");
        return;
    }

    struct node* ptr = top;

    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Display element at particular position
void displayatpos(int pos){

    if(isempty()){
        printf("The stack is empty\n");
        return;
    }

    struct node* ptr = top;
    int i = 1;

    while(ptr != NULL && i < pos){
        ptr = ptr->next;
        i++;
    }

    if(ptr == NULL){
        printf("Invalid Position\n");
    }
    else{
        printf("The value at %d from top is %d\n", pos, ptr->data);
    }
}

// Main Function
int main(){

    // Pushing elements
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);

    printf("\nStack Elements:\n");
    display();

    printf("\n");

    // Popping elements
    pop();
    pop();

    printf("\n");

    // Display at position
    displayatpos(1);

    printf("\n");

    pop();
    pop();
    pop();
    pop();
    pop();

    printf("\n");

    // Peek element
    peek();

    return 0;
}