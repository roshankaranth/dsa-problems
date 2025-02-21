#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include "personMerge.h"
#include "person.h"

void mergeSort(Person A[], int s, int e){
    if(s==e) return;

    int mid = (s+e)/2;

    mergeSort(A,s,mid);
    mergeSort(A,mid+1,e);
    merge(A,s,mid,e);

}

Person itoe(int id, char* name, int age, int height, int weight, int i){
    Person p; 
    p.age = age;
    strcpy(p.name,name);
    p.height = height;
    p.weight = weight;
    p.id = id;

    return p;
}

void displayArray(Person* p, int n){
    for(int i = 0 ; i < n ; i++){
        printf("\n%d %s %d %d %d", (p+i)->id, (p+i)->name, (p+i)->age, (p+i)->height, (p+i)->weight);
    }
}

void auxMergeSortFile(int size, Person p[], int f){
            
        mergeSort(p,0,size-1);
        
        char fname[20];
        sprintf(fname, "f%d_aux.csv", f);
        FILE* nptr = fopen(fname,"w");
        if(nptr == NULL) {
            printf("Error opening file!");
            exit(0);
        }

        for(int j = 0 ; j < size ; j++){
            fprintf(nptr, "%d %s %d %d %d\n", p[j].id, p[j].name, p[j].age, p[j].height, p[j].weight);
        }
}

void main(int argc, char* argv[]){

    struct timeval t1,t2;
    double time_taken = 0;

    int size = atoi(argv[2]);
    Person* p = (Person*)malloc(sizeof(Person)*(size));
    FILE* fptr = fopen(argv[1], "r");
    if(fptr == NULL){
        printf("Error opening file!");
        exit(0);
    }
    char line[100];
    int count = 0;
    int i = 0;
    int f = 0;
    while(fgets(line, 100, fptr)){
    
       char* token = strtok(line,",");
       int id = atoi(token);
       token = strtok(NULL, ",");
       char name[100];
       strcpy(name,token);
       token = strtok(NULL, ",");
       int age = atoi(token);
       token = strtok(NULL, ",");
       int height = atoi(token);
       token = strtok(NULL, ",");
       int weight = atoi(token);
       token = strtok(NULL, ",");
       p[i] = itoe(id,name,age,height,weight,i);

       if(i == size-1){
        gettimeofday(&t1,NULL);
        auxMergeSortFile(i+1,p,f);
        gettimeofday(&t2,NULL);

        time_taken += (t2.tv_sec - t1.tv_sec) ;
        time_taken += (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

        f++;
        i=0;
            
       }else i++;

       
    }

    if(i!=0){
        gettimeofday(&t1,NULL);
        auxMergeSortFile(i+1,p,f);
        gettimeofday(&t2,NULL);
    }
    
    time_taken += (t2.tv_sec - t1.tv_sec) ;
    time_taken += (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("The task took %f seconds to execute.\n", time_taken);
    

}