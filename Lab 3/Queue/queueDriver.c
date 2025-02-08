#include "queue.h"
#include <stdio.h>
#include <sys/time.h>

Element itoe (int i);
int main()
{   
     printf("\nHeap memeory allocated : %ld\n", heapMemoryAllocated);
     Queue* q = createQueue();

      if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }
    printf("\nHeap memeory allocated : %ld\n", heapMemoryAllocated);
    // Enqueue elements
    for (int i = 1; i <= 10; i++) {
        if (!enqueue(q, itoe(i))) {
            printf("Queue is full!\n");
        }
    }
    printf("\nHeap memeory allocated : %ld\n", heapMemoryAllocated);
    // Print front element
    Element* frontElement = front(q);
    if (frontElement) {
        printf("Front element: %d\n", frontElement->int_value);
    } else {
        printf("Queue is empty!\n");
    }

    // Dequeue elements
    while (!isEmpty(q)) {
        printf("Dequeued element: %d\n", front(q)->int_value);
        dequeue(q);
    }
    printf("\nHeap memeory allocated : %ld\n", heapMemoryAllocated);
    // Check if queue is empty
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }

    // Destroy the queue
    destroyQueue(q);
    printf("\nHeap memeory allocated : %ld\n", heapMemoryAllocated);
    return 0;
}

Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}