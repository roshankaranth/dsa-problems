#ifndef ELEMENT_H
#define ELEMENT_H
typedef struct Element
{
    int pid;
    int arrival_time;
    int burst_time;
}Element;

#endif

// #ifndef ELEMENT ... #endif is a common pattern to prevent multiple
// inclusion of a header file.  It is not necessary in this case, but
// it is good practice to use it anyway.