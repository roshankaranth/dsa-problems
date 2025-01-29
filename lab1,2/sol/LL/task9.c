#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

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

int hasCycle(LIST l){
    
    NODE sptr = l->head;
    NODE fptr = l->head;

    while(sptr!=NULL && fptr!=NULL && fptr->next != NULL){
        sptr = sptr->next;
        fptr = fptr->next;
        fptr = fptr->next;
        
        if(sptr == fptr) return 1;
    } 

    return 0;
}

void main(){

    struct timeval t1,t2;
    double time_taken;

    gettimeofday(&t1, NULL);

    LIST sl = createNewList();

    for(int i = 7 ; i >= 1 ; i--){
        NODE n = createNewNode(i);
        insertFirst(sl,n);
    }

    if(hasCycle(sl)) printf("single Linked list has cycle!\n");
    else printf("single Linked list has no cycle!\n");

    LIST cl = createNewList();

    NODE cstart = NULL;
    NODE cend = NULL;

    for(int i = 7 ; i >= 1 ; i--){
        NODE n = createNewNode(i);
        if(i==7) cend = n;
        if(i==3) cstart = n;
        insertFirst(cl,n);
    }

    cend->next = cstart;

    if(hasCycle(cl)) printf("cyclic Linked list has cycle!\n");
    else printf("cyclic linked list has no cycle!\n");

    LIST ccl = createNewList();

    NODE start = NULL;
    NODE end = NULL;

    for(int i = 7 ; i >= 1 ; i--){
        NODE n = createNewNode(i);
        if(i==7) end = n;
        if(i==1) start = n;
        insertFirst(ccl,n);
    }

    end->next = start;

    if(hasCycle(ccl)) printf("circular Linked list has cycle!\n");
    else printf("circular linked list has no cycle!\n");

    gettimeofday(&t2, NULL);

    time_taken = (t2.tv_sec - t1.tv_sec)*1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("\nThe tasks took %f seconds to exectue!\n",time_taken);
}