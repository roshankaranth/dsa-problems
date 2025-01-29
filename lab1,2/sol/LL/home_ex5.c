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

void insertFirst(LIST l, NODE n){

    n->next = l->head;
    l->head = n;
    l->count++;
    return;

}

void reverseLL(LIST l){
    
    if(l->head == NULL) return;
    NODE sptr = l->head;
    NODE tptr = NULL;
    NODE pptr = NULL;

    while(sptr!=NULL){
        tptr = sptr->next;
        sptr->next = pptr;
        pptr = sptr;
        sptr = tptr;
        
        
    }

    l->head = pptr;

}

void main(){

    LIST l = createNewList();

    for(int i = 5 ; i >= 0 ; i--){
        NODE n = createNewNode(i);
        insertFirst(l,n);
    }
    printList(l);
    reverseLL(l);
    printList(l);
}