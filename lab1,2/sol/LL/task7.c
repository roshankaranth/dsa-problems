#include<stdio.h>
#include<stdlib.h>

typedef struct Node* NODE;
struct Node{
    int ele;
    NODE next;
};

typedef struct List* LIST;
struct List{
    int count;
    NODE head;
};

LIST createNewList(){
    
    LIST l = (LIST)malloc(sizeof(struct List));
    l->count = 0;
    l->head = NULL;
    return l;
     
}

NODE createNewNode(int value){

    NODE n = (NODE)malloc(sizeof(struct Node));
    n->ele = value;
    n->next = NULL;
    return n;

}

void insertAfter(int searchEle, NODE n, LIST l){

    if(l->head == NULL){
        l->head = n;
        n->next = NULL;
        l->count++;
        return;
    }

    NODE ptr = l->head;
    while(ptr != NULL){
        if(ptr->ele == searchEle) break;
        ptr = ptr->next;
    }

    if(ptr==NULL){
        printf("\nElement not found!\n");
        return;
    }

    n->next = ptr->next;
    ptr->next = n;
    l->count++;

    return;

}

void printList(LIST l){
   
    NODE ptr = l->head;
    printf("[HEAD] -> ");
    while(ptr!=NULL){
        printf("%d -> ", ptr->ele);
        ptr = ptr->next;
    }

    printf("[NULL]\n");

    return;
}

void deleteAt(NODE n, LIST l){

    NODE ptr = l->head;
    NODE prev = NULL;
    while(ptr!=NULL){
        if(ptr==n) break;
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr==NULL){
        printf("\nNode not found!");
        return;
    }

    if(prev==NULL){
        l->head = ptr->next;
    }else{
        prev->next = ptr->next;
    }
    free(ptr);
    ptr = NULL;
    l->count--;
    return;

}

NODE search(int val, LIST l){

    NODE ptr = l->head;

    while(ptr != NULL){
        if(ptr->ele == val) break;
        ptr = ptr->next;
    }

    if(ptr==NULL) {
        printf("\nValue not found!");

    }

    return ptr;
}

void insertFirst(LIST l, NODE n){

    n->next = l->head;
    l->head = n;
    l->count++;
    return;

}

void deleteFirst(LIST l){

    if(l->head==NULL){
        printf("\nList Empty!");
        return;
    }

    NODE ptr = l->head;
    l->head = ptr->next;
    free(ptr);
    ptr = NULL;
    l->count--;
    return;

}

