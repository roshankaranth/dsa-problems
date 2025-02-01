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

void dataDMA(STUDENT ptr){

    FILE* fptr = fopen("../../data.txt","r");
    char line[100];
    int student = 0;
    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        strcpy(ptr[student].ID, token);
        token = strtok(NULL,",");
        ptr[student].CGPA = atof(token);
        student++;
    }

    fclose(fptr);

}

void insertNode(NODE n, LIST l){
    NODE temp = l->head;
    l->head = n;
    n->next = temp;
    l->count++;
}

void dataLL(LIST l){

    FILE* fptr = fopen("../../data.txt","r");
    char line[100];
    while(fgets(line,100,fptr)){
        NODE n = (NODE)malloc(sizeof(node));
        char* token = strtok(line,",");
        strcpy(n->ID, token);
        token = strtok(NULL,",");
        n->cgpa = atof(token);
        insertNode(n,l);
    }

}

void updateData_DA(student record[], int pos[], STUDENT ptr){
    
    ptr = (STUDENT)realloc(ptr,sizeof(student)*(TOTAL_STUDENTS + 10 ));
    int size = TOTAL_STUDENTS + 10;
    for(int i = 0 ; i < 10; i++){
        for(int j = size-10-1+i ; j>=pos[i] ; j-- ){
            ptr[j+1].CGPA = ptr[j].CGPA;
            strcpy(ptr[j+1].ID, ptr[j].ID);
        }

        ptr[pos[i]].CGPA = record[i].CGPA;
        strcpy(ptr[pos[i]].ID, record[i].ID);

    }

}

void updateData_LL(student record[], int pos[], LIST l){

     for(int i = 0 ; i < 10; i++){
        int ctr = 0;
        NODE ptr = l->head;
        NODE prev = NULL;
        while(ptr!=NULL){
            if(ctr==(TOTAL_STUDENTS + 10 -1) - pos[i]) break;
            prev = ptr;
            ptr = ptr->next;
            ctr++;
        }

        NODE n = (NODE)malloc(sizeof(node));
        n->cgpa = record[i].CGPA;
        strcpy(n->ID,record[i].ID);
        n->next = ptr;
        if(prev!=NULL)prev->next = n;
        else l->head = n;
        l->count++;
    }

}

NODE getData_LL(int pos, LIST l){

    NODE ptr = l->head;
    int ctr = 0;
    while(ptr != NULL){
        if(ctr==(TOTAL_STUDENTS + 10 -1) - pos) break;
        ptr = ptr->next;
        ctr++;
    }

    return ptr;
}

STUDENT getData_DA(int pos, STUDENT ptr){
    
    return &ptr[pos]; 

}

void deleteData_DA(STUDENT ptr){

    for(int i = 0 ; i < TOTAL_STUDENTS + 10 ; i++){
        ptr[i].CGPA = 0;
        strcpy(ptr[i].ID, "");
    }

    free(ptr);
    ptr = NULL;

}

void deleteData_LL(LIST l){

    NODE ptr = l->head;
    NODE prev = NULL;
    while(ptr!=NULL){
        prev = ptr;
        ptr = ptr->next;
        free(prev);

    }

    free(l);
    prev = NULL;
    l = NULL;
}

void main(void){

    struct timeval t1,t2;
    double time_taken_DA;
    double time_taken_LL;

    STUDENT ptr = (STUDENT)malloc(sizeof(student)*TOTAL_STUDENTS);
    printf("Reading and writing data into dynamic array.\n");

    gettimeofday(&t1,NULL);
    dataDMA(ptr);
    gettimeofday(&t2,NULL);

    time_taken_DA = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_DA = (time_taken_DA + (t2.tv_usec - t1.tv_usec)) * 1e-6; 
    
    printf("Reading and writing to dynamic array took %f second\n\n", time_taken_DA);

    LIST l = (LIST)malloc(sizeof(list));
    l->count = 0;
    l->head = NULL;
    printf("Reading and writing data into LL.\n");
    gettimeofday(&t1,NULL);
    dataLL(l);
    gettimeofday(&t2,NULL);

    time_taken_LL = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_LL = (time_taken_LL + (t2.tv_usec - t1.tv_usec)) * 1e-6; 

    printf("Reading and writing to linked list took %f second\n", time_taken_LL);

    printf("\nEnter 10 new entries, and the index of insertion\n");
    student record[10];
    int pos[10];
    for(int i = 0 ;  i < 10 ; i++){
        scanf("%s %f %d", record[i].ID, &record[i].CGPA, &pos[i]);
    }

    printf("\nInserting records into dynamic array\n");
    gettimeofday(&t1,NULL);
    updateData_DA(record, pos, ptr);
    gettimeofday(&t2,NULL);

    time_taken_DA = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_DA = (time_taken_DA + (t2.tv_usec - t1.tv_usec)) * 1e-6; 
    
    printf("Inserting to dynamic array took %f second\n\n", time_taken_DA);

    printf("Inserting records into linkedlist\n");
    gettimeofday(&t1,NULL);
    updateData_LL(record,pos,l);
    gettimeofday(&t2,NULL);

    time_taken_LL = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_LL = (time_taken_LL + (t2.tv_usec - t1.tv_usec)) * 1e-6; 

    printf("Inserting to linked list took %f second\n", time_taken_LL);

    int x = 0;
    printf("\nEnter position for data retrival (0-10009) : ");
    scanf("%d", &x);

    printf("\nFetching record from dynamic array\n");
    gettimeofday(&t1,NULL);
    STUDENT s = getData_DA(x, ptr);
    gettimeofday(&t2,NULL);

    printf("Students ID : %s\n", s->ID);
    printf("Students CGPA : %f\n", s->CGPA);

    time_taken_DA = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_DA = (time_taken_DA + (t2.tv_usec - t1.tv_usec)) * 1e-6; 

    printf("Fetching data from dynamic array took %f second\n", time_taken_DA);

    printf("\nFetching record from linked list\n");
    gettimeofday(&t1,NULL);
    NODE sn = getData_LL(x,l );
    gettimeofday(&t2,NULL);

    printf("Students ID : %s\n", sn->ID);
    printf("Students CGPA : %f\n", sn->cgpa);

    time_taken_LL = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_LL = (time_taken_LL + (t2.tv_usec - t1.tv_usec)) * 1e-6; 

    printf("Fetching data from linked list took %f second\n", time_taken_LL);

    printf("\nDeleting entries from dynamic array\n");
    gettimeofday(&t1,NULL);
    deleteData_DA(ptr);
    gettimeofday(&t2,NULL);

    time_taken_DA = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_DA = (time_taken_DA + (t2.tv_usec - t1.tv_usec)) * 1e-6; 

    printf("Deleting data from dynamic array took %f second\n", time_taken_DA);

    printf("\nDeleting entries from linked list\n");
    gettimeofday(&t1,NULL);
    deleteData_LL(l);
    gettimeofday(&t2,NULL);

    time_taken_LL = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken_LL = (time_taken_LL + (t2.tv_usec - t1.tv_usec)) * 1e-6; 
    
    printf("Deleting data from dynamic array took %f second\n", time_taken_LL);


}

//inside a function, the array when passed, is passed as a pointer. thus when we do sizeof() it gives size of pointer and not the array.