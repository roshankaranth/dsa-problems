#include "linked_list.h"
#include "stack.h"

typedef struct Stack{
    LIST data;
}Stack;

Stack* newStack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if(s!=NULL){
        s->data = createNewList();
    }
    
    return s;
}

bool push(Stack* stack, Element element){
    NODE n = createNewNode(element);
    insertNodeIntoList(n,stack->data);
    return true;
}

Element* top(Stack *stack){
    if(stack->data->count == 0) return NULL;
    return &stack->data->head->data;
}

bool pop(Stack* stack){
    if(stack->data->count == 0) return false;
    removeFirstNode(stack->data);
    return true;
}

bool isEmpty(Stack* stack){
    if(stack->data->count == 0 ) return true;
    return false;
}

void freeStack(Stack *stack){
    destroyList(stack->data);
    free(stack);
    stack = NULL;
}
