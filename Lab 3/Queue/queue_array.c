#include "queue.h"
#include <stdlib.h>

#define QUEUE_SIZE 5

struct Queue {
    int front;
    int rear;
    int size;
    Element data[QUEUE_SIZE];
};

Queue* createQueue(){
    Queue* q = (Queue*)myalloc(sizeof(Queue));
    if(q!=NULL){
        q->front = 0;
        q->rear = 0;
        q->size = 0;
    } 

    return q;
}

bool enqueue(Queue *queue, Element element){
    if(queue->size == QUEUE_SIZE){
        return false;
    }

    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->size++;
    return true;

}

bool dequeue(Queue* queue){
    if(queue->size == 0){
        return false;
    }

    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->size--;
}

Element* front(Queue* queue){
    if(queue->size == 0) return NULL;

    return &queue->data[queue->front];
}

int size(Queue* queue){
    return queue->size;
}

bool isEmpty(Queue* queue){
    if(queue->size == 0) return true;
    return false;
}

void destroyQueue(Queue* queue){
    myfree(queue);
    queue = NULL;
}

