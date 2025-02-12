#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>

typedef struct person{
    int id;
    char name[100];
    int age;
    int height;
    int weight;
}Person;

void insertionSort(Person* A, int n){
    for(int i = 1 ; i < n ; i++){
        Person p = A[i];
        int j = i-1;
        while(j>=0 && A[j].height > p.height){
            A[j+1] = A[j];
            j--; 
        }

        A[j+1] = p;
    }
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

void main(int argc, char* argv[]){

    struct timeval t1,t2;
    double time_taken;

    int size = atoi(argv[2]);
    Person* p = (Person*)malloc(sizeof(Person)*(size));
    FILE* fptr = fopen(argv[1], "r");
    if(fptr == NULL){
        printf("Error opening file!");
        exit(0);
    }
    char line[100];
    int i = 0;
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
        i++;
    }

    //displayArray(p,size);
    gettimeofday(&t1,NULL);
    insertionSort(p,size);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("The task took %f seconds to execute\n", time_taken);

    //printf("\n");
    //displayArray(p,size);
    

}