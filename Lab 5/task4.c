#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>

typedef struct node * NODE;
struct node{
    int ele;
    NODE next;
};


typedef struct linked_list * LIST;
struct linked_list{
    int count;
    NODE head;
};


LIST createNewList()
{
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}


NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->ele=value;
    myNode->next=NULL;
    return myNode;
}

// Recursive function to compute sum of integers in a linked list
long long int llSumNTR(NODE head)
{
    if (head == NULL)
        return 0;
    return head->ele + llSumNTR(head->next); // Pay close attention here
}

long long int llSumTR(NODE head, long long int sum){
    if(head == NULL) return sum;

    return llSumTR(head->next, head->ele + sum);
}

long long int llSumIter(NODE head){
    long long int sum = 0;
    while(head != NULL){
        sum += head->ele;
        head = head->next;
    }

    return sum;
}

// This is just a wrapper function to take LIST as input, but run the recursive sum function on its NODEs starting from the head
long long int llSumNTRWrapper(LIST list)
{
    return llSumNTR(list->head);
}

long long int llSumTRWrapper(LIST list)
{
    long long int sum = 0;
    return llSumTR(list->head, sum);
}

long long int llSumIterWrapper(LIST list)
{
    return llSumIter(list->head);
}

// Driver code
int main()
{
    // Reads the file numbers1000.txt and creates a linked list with those integers
    FILE *fp;
    fp = fopen("input_files/numbers100000.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int num;
    LIST myList = createNewList();
    while (fscanf(fp, "%d", &num) != EOF)
    {
        NODE myNode = createNewNode(num);
        myNode->next = myList->head;
        myList->head = myNode;
        myList->count++;
    }
    fclose(fp);

    struct timeval t1,t2;
    double time_taken = 0;
    long long int res;

    gettimeofday(&t1,NULL);
    res = llSumNTRWrapper(myList);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken = (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nSum calculated using the NTR function : %lld", res);
    printf("\nNTR approach took %f seconds to execute\n", time_taken);

    gettimeofday(&t1,NULL);
    res = llSumTRWrapper(myList);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken = (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nSum calculated using the TR function : %lld", res);
    printf("\nTR approach took %f seconds to execute\n", time_taken);

    gettimeofday(&t1,NULL);
    res = llSumIterWrapper(myList);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken = (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nSum calculated using the Iterative function : %lld", res);
    printf("\nIterative approach took %f seconds to execute\n", time_taken);


    
}