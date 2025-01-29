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

void rotate(int k, LIST l){
    
    k = k%l->count;
    if(k==0) return;

    NODE eptr = l->head;
    NODE kptr = l->head;
    k--;
    while(eptr->next !=NULL){
        eptr  = eptr->next ;
        if(k){ kptr = kptr->next; k--;}
        
    }

    eptr->next = l->head;
    l->head = kptr->next;
    kptr->next = NULL;


    // NODE sptr = l->head;
    // while(sptr!=kptr){
    //     eptr->next = sptr;
    //     sptr = sptr->next;
    //     eptr = eptr->next;
    //     eptr->next = NULL;
    // }

    // l->head = sptr;

}

void main(){

    LIST l = createNewList();

    for(int i = 5 ; i >= 1 ; i--){
        NODE n = createNewNode(i);
        insertFirst(l,n);
    }

    printList(l);

    rotate(6,l);

    printList(l);
}