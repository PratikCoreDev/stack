#include<stdio.h>
#include<stdlib.h>
struct stack{  //structure of stack
    int size;
    int top;
    int* arr;
};

//isempty function to check the stack is empty or not
int isempty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

//isfull function to check the stack is full or not
int isfull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

//push function to push element in the stack
void push(struct stack* ptr,int val){
    if(isfull(ptr)){
        printf("The stack is full,unable to insert %d \n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
        printf("Successfully inserted %d \n",val);
    }
}

//pop function to pop element in the stack
void pop(struct stack* ptr){
    if(isempty(ptr)){
        printf("The stack is empty,unable to pop \n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        printf("Successfully deleted %d \n",val);
    }
}

//finding peak element
void peek(struct stack* ptr){
    if(isempty(ptr)){
        printf("There is not value in the stack \n");
    }
    else{
        int val=ptr->arr[ptr->top];
        printf("The peek element in the stack is: %d \n",val);
    }
}

//display element of the stack
void display(struct stack* ptr){
    for(int i=ptr->top;i>=0;i--){
        printf("elements: %d \n",ptr->arr[i]);
    } 
}

//display the data at particular position
void displayatpos(struct stack* ptr,int pos){
    int index=ptr->top-pos+1;
    if(index<0 || index>ptr->top){
        printf("Invalid index");
    }
    else{
        printf("The value at %d from top is %d \n",pos,ptr->arr[index]);
    }
}

//main function
int main(){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));//initializing stack
    s->size=6; //initializing stack max size
    s->top=-1;//initializing the top of stack
    s->arr=(int*)malloc(s->size*sizeof(int)); // making of array

    //pushing element in stacks till full
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    push(s,7);

    //display elements of the stack
    display(s);

    //popping element in stack till empty
    pop(s);
    pop(s);

    //display at particular position
    displayatpos(s,1);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);

    //peek element of the stack
    peek(s);

    //free memory
    free(s->arr);
    free(s);

    return 0;
}