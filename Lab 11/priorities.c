#include <stdio.h>
#include <stdlib.h>

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
        h->data = (int*)realloc(h->data,sizeof(int)*(power(2,h->depth+1) -1));
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

void max_heapify(Heap* h, int index){
    
    int left = left_child(h,index);
    int right = right_child(h,index);
    int largest = index;

    if(left < h->size && h->data[left] > h->data[largest]){
        largest = left;
    }

    if(right < h->size && h->data[right] > h->data[largest]){
        largest = right;
    }

    if(largest != index){
        int temp = h->data[index];
        h->data[index] = h->data[largest];
        h->data[largest] = temp;
        max_heapify(h,largest);
    }
}

Heap* build_max_heap(Heap* h){
    int size =h->size;

    for(int i = h->size-1 ; i>= 0 ;i--){
        max_heapify(h,i);
    }

    return h;
}

void increase_key(Heap* h, int x, int k)
{
    h->data[x] = k;
    // Complete the function here
    int iparent = parent(h,x);
    int index = x;

    if(iparent >= 0 && h->data[iparent] < h->data[index]){
        index = iparent;
    }

    if(index != x){
        h->data[x] = h->data[iparent];
        h->data[iparent] = k;
        increase_key(h,iparent,k);
    }

    return;
}

void insert(Heap* h, int value)
{
    add_to_tree(h, value);
    // Complete the function here
    increase_key(h,h->size-1,value);
    return;
}

int maximum(Heap* h)
{
    if (h->size == 0)
        return -1;    // -1 denotes that the heap is empty
    else
        return h->data[0];
}

int extract_maximum(Heap* h)
{
    int max = maximum(h);
    // Complete the function here
    h->data[0] = h->data[h->size-1];
    h->size--;
    max_heapify(h,0);

    return max;
}

int isEmpty(Heap* h){
    if(h->size == 0) return 1;
    return 0;
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
    add_to_tree(h,5);

    display(h);
    build_max_heap(h);
    display(h);
    insert(h,45);
    display(h);
    printf("%d\n", maximum(h));
    extract_maximum(h);
    display(h);
    
    while(!isEmpty(h)){
        printf("%d ", extract_maximum(h));
    }

}