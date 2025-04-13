#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
    int *data;
    int size;
    int capacity;
    int depth;
}Heap;

Heap* heap_create(){
    Heap* h = (Heap*)malloc(sizeof(Heap));

    h->data = (int*)malloc(sizeof(int));
    h->size = 0;
    h->capacity = 1;
    h->depth = 0;

    return h;
}

int power(int a, int n){
    int res = 1;
    for(int i = 0 ; i < n ; i++){
        res *= a;
    }

    return res;
}

void add_to_tree(Heap* h, int val){
    
    if(h->capacity == h->size){
        h->depth++;
        h->data = (int*)realloc(h->data,sizeof(Heap)*(power(2,h->depth+1) -1));
        h->capacity = power(2,h->depth+1)-1;

    }

    h->data[h->size] = val;
    h->size++;

}

int parent(Heap* h, int node){
    return (node-1)/2;
}

int left_child(Heap* h, int node){
    return 2*(node) + 1;
}

int right_child(Heap* h, int node){
    return 2*(node) + 2;
}

void display(Heap* h){
    for(int i = 0 ; i < h->size ; i++){
        printf("%d ",h->data[i]);
    }
    printf("\n");
}

void main(){
    Heap* h = heap_create();

    add_to_tree(h,1);
    add_to_tree(h,4);
    add_to_tree(h,2);
    add_to_tree(h,3);
    add_to_tree(h,9);
    add_to_tree(h,7);
    add_to_tree(h,8);
    add_to_tree(h,10);
    add_to_tree(h,14);
    add_to_tree(h,16);

    display(h);

    return;
}