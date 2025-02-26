#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct person {
    int id;
    char name[100];
    int age;
    int height;
    int weight;

}Person;

Person itoe(int ID, char* name, int age, int height, int weight){
    Person p;
    p.id = ID;
    strcpy(p.name, name);
    p.age = age;
    p.height = height;
    p.weight = weight;

    return p;
}

void display(Person* data, int size){
    for(int i = 0 ; i < size; i ++){
        printf("%d %s %d %d %d\n", data[i].id, data[i].name, data[i].age, data[i].height, data[i].weight);
    }
}



void main(int argc, char* argv[]){
    int size = atoi(argv[2]);
    FILE* fptr = fopen(argv[1], "r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    Person* data = (Person*)malloc(sizeof(Person)*size);

    char line[100];
    int i = 0;
    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        int ID = atoi(token);
        token = strtok(NULL,",");
        char* name = token;
        token = strtok(NULL,",");
        int age = atoi(token);
        token = strtok(NULL,",");
        int height = atoi(token);
        token = strtok(NULL,",");
        int weight = atoi(token);

        data[i] = itoe(ID, name, age, height, weight);
        i++;

    }

    //display(data, size);

}