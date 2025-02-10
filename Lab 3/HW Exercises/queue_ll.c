#include "linked_list.h"
#include "queue.h"

typedef struct Queue{
    LIST data;
}Queue;

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q!=NULL){
        q->data = createNewList();
    } 

    return q;
}

bool enqueue(Queue *queue, Element element){
    NODE n = createNewNode(element);
    if(n==NULL) return false;
    insertNodeAtEnd(n,queue->data);

    return true;
}

bool dequeue(Queue* queue){
    
    if(queue->data->count==0) return false;
    removeFirstNode(queue->data);

    return true;
}

Element* front(Queue* queue){
    if(queue->data->count == 0) return NULL;
    return &queue->data->head->data;
}

int size(Queue *queue){
    return queue->data->count;
}

bool isEmpty(Queue* queue){
    if(queue->data->count == 0) return true;
    return false;
}

void destroyQueue(Queue* queue){
    destroyList(queue->data);

    free(queue);
    queue = NULL;
}