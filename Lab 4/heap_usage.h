#ifndef HEAP_USAGE_H
#define HEAP_USAGE_H
#include <stdlib.h>
extern size_t heapMemoryAllocated;
extern size_t totalHeapMemoryAllocated;
void *myalloc(size_t size);
void myfree(void *ptr);
#endif