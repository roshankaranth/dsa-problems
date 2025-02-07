#include "stack.h"
#include <stdio.h>
#include <sys/time.h>

Element itoe (int i);
int main()
{   
    struct timeval t1,t2;
    double time_taken;

    gettimeofday(&t1,NULL);
    printf("Heap Memory used : %ld \n", heapMemoryAllocated);
    Stack *s = newStack();
    if(isEmpty(s))
        printf("Stack is empty\n");
    printf("Heap Memory used : %ld \n", heapMemoryAllocated);
    push(s, itoe(1));
    int value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    push(s, itoe(2));
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    
    printf("Heap Memory used : %ld \n", heapMemoryAllocated);
    
    if(!isEmpty(s))
        printf("Stack is not empty\n");

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    
    pop(s);
    
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Pop returned %s\n", pop(s)?"true":"false");
   
    printf("Heap Memory used : %ld \n", heapMemoryAllocated);
    printf("Trying to pop an empty stack\n");
    printf("Pop returned %s\n", pop(s)?"true":"false");

    freeStack(s);
    printf("Heap Memory used : %ld \n", heapMemoryAllocated);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("The tasks took %f seconds to execute\n", time_taken);

    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}