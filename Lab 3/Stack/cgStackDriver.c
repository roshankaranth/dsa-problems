#include "stack.h"
#include "heap_usage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
Element iftoe (int i, float f);
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    char *line = malloc(100); 
    /* 
    Here we used malloc() and not myalloc() because as do not want to track 
    the memory usage of the line variable. We only want to track the heap
    usage of the stack.
    */

    Stack *s = newStack();
    struct timeval t1,t2;
    double time_taken;

    int score = 0;
    float cg = 0;
    int i = 0;
    while(fgets(line, 100, fp) != NULL)
    {
        char *token;
        token = strtok(line, ",");
        score = atoi(token);
        token = strtok(NULL, ",");
        cg = atof(token);
        // printf("%d: Score: %d, CG: %f\n", i, score, cg);
        // You can uncomment the above line to print the values read from the file
            
        gettimeofday(&t1,NULL);
        push(s,iftoe(score,cg));
        gettimeofday(&t2,NULL);

        time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
        time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
        i++;
    }
    fclose(fp);

    printf("Heap Memory used : %ld \n", heapMemoryAllocated);
    printf("The tasks took %f seconds to execute\n", time_taken);
    printf("\nRemoving elements\n");
    gettimeofday(&t1,NULL);
    while(!isEmpty(s)){ 
        pop(s);
    }
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("\nHeap Memory used : %ld \n", heapMemoryAllocated);
    printf("The tasks took %f seconds to execute\n", time_taken);
}
Element iftoe (int i, float f)
{
    Element e;
    e.int_value = i;
    e.float_value = f;
    return e;
}