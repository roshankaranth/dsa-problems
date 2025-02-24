#include<stdio.h>
#include<stdbool.h>

typedef struct priorityQueue{
    int arr[10];
    int size;
}priorityQueue;

priorityQueue createPriorityQueue(){
    priorityQueue p;
    p.size = 0;

    return p;
}

void increaseKey(priorityQueue* p, int x, int ind){
    int smallest = ind;
    p->arr[ind] = x;
    if(ind == 0) return;
    if(p->arr[ind] > p->arr[(ind-1)/2]){
        smallest = (ind-1)/2;
    }

    if(smallest != ind){
        int temp = p->arr[ind];
        p->arr[ind] = p->arr[smallest];
        p->arr[smallest] = temp;

        increaseKey(p,x,smallest);
    }
    
}

void insertPriorityQueue(priorityQueue* p, int x){
    p->arr[p->size] = -1;
    p->size++;
    increaseKey(p,x,p->size-1);
}

int top(priorityQueue* p){
    if(p->size == 0) return -1;
    return p->arr[0];
}

void heapify(priorityQueue* p, int ind)
{
    int largest = ind;
    int left = 2*ind+1;
    int right = 2*ind + 2;

    if(left < p->size && p->arr[left] > p->arr[largest]){
        largest = left;
    }

    if(right < p->size && p->arr[right] > p->arr[largest]){
        largest = right;
    }

    if(largest != ind){
        int temp = p->arr[ind];
        p->arr[ind] = p->arr[largest];
        p->arr[largest] = temp;

        heapify(p,largest);
    }
}
int deleteKey(priorityQueue* p){
   int num = p->arr[0];
   p->arr[0] = p->arr[p->size-1];
   p->size--;

   heapify(p,0);

   return num;

}

bool isEmpty(priorityQueue* p){
    if(p->size == 0) return true;
    else return false;
}

int size(priorityQueue* p){
    return p->size;
}




void main(){

    priorityQueue p = createPriorityQueue();

    insertPriorityQueue(&p,10);
    printf("%d %d\n", top(&p), p.size);
    insertPriorityQueue(&p,12);
    printf("%d %d\n", top(&p), p.size);
    insertPriorityQueue(&p,13);
    printf("%d %d\n", top(&p), p.size);
    insertPriorityQueue(&p,7);
    printf("%d %d\n", top(&p), p.size);
    insertPriorityQueue(&p,16);
    printf("%d %d\n", top(&p), p.size);
    insertPriorityQueue(&p,14);
    printf("%d %d\n", top(&p), p.size);
    printf("deleting keys \n");
    
    deleteKey(&p);
    printf("%d %d\n", top(&p), p.size);
    deleteKey(&p);
    printf("%d %d\n", top(&p), p.size);
    deleteKey(&p);
    printf("%d %d\n", top(&p), p.size);
    deleteKey(&p);
    printf("%d %d\n", top(&p), p.size);
    deleteKey(&p);
    printf("%d %d\n", top(&p), p.size);
    deleteKey(&p);
    printf("%d %d\n", top(&p), p.size);



}