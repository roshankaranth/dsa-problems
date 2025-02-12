#include<stdio.h>
#include<stdlib.h>

typedef struct person{
    int id;
    char *name;
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

void itoe(Person* p, int id, char* name, int age, int height, int weight){
    p->age = age;
    p->name = name;
    p->height = height;
    p->weight = weight;
    p->id = id;
}

void displayArray(Person* p, int n){
    for(int i = 0 ; i < n ; i++){
        printf("\n%d %s %d %d %d", (p+i)->id, (p+i)->name, (p+i)->age, (p+i)->height, (p+i)->weight);
    }
}

void main(){
    Person* p = (Person*)malloc(sizeof(Person)*5);

    itoe(p,1,"Sokka",15,150,45);
    itoe(p+1,2,"Aang",112,137,35);
    itoe(p+2,3,"Zuko",16,160,50);
    itoe(p+3,4,"Katara",14,145,38);
    itoe(p+4,5,"Toph",12,113,30);

    displayArray(p,5);

    insertionSort(p,5);
    printf("\n");
    displayArray(p,5);
    

}