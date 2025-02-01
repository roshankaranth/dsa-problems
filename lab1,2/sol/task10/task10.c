#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

#define TOTAL_STUDENTS 10000

typedef struct student {
    char ID[15];
    float CGPA;
}student;

typedef student* STUDENT;
typedef struct node* NODE;
typedef struct node{
    char ID[15];
    float cgpa;
    NODE next;
}node;

typedef struct list{
    NODE head;
    int count;
}list;

typedef list* LIST;

void dataDMA(){

    STUDENT ptr = (STUDENT)malloc(sizeof(student)*TOTAL_STUDENTS);
    FILE* fptr = fopen("../../data.txt","r");
    char line[100];
    int student = 0;
    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        strcpy(ptr[student].ID, token);
        token = strtok(NULL,",");
        ptr[student].CGPA = atof(token);
    }

    fclose(fptr);

}

void insertNode(NODE n, LIST l){
    NODE temp = l->head;
    l->head = n;
    n->next = temp;
}

void dataLL(){

    LIST l = (LIST)malloc(sizeof(list));
    FILE* fptr = fopen("../../data.txt","r");
    char line[100];
    int student = 0;
    while(fgets(line,100,fptr)){
        NODE n = (NODE)malloc(sizeof(node));
        char* token = strtok(line,",");
        strcpy(n->ID, token);
        token = strtok(NULL,",");
        n->cgpa = atof(token);
        insertNode(n,l);
    }

}


void main(void){

    struct timeval t1,t2;
    double time_taken_DA;
    double time_taken_LL;


    printf("Reading and writing data into dynamic array.\n");

    gettimeofday(&t1,NULL);
    dataDMA();
    gettimeofday(&t2,NULL);

    time_taken_DA = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_DA = (time_taken_DA + (t2.tv_usec - t1.tv_usec)) * 1e-6; 
    
    printf("Reading and writing to dynamic array took %f second\n\n", time_taken_DA);


    printf("Reading and writing data into LL.\n");
    gettimeofday(&t1,NULL);
    dataLL();
    gettimeofday(&t2,NULL);

    time_taken_LL = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_LL = (time_taken_LL + (t2.tv_usec - t1.tv_usec)) * 1e-6; 

    printf("Reading and writing to linked list took %f second\n", time_taken_LL);







}