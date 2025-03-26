#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student{
    long long int ID;
    char name[30];
}Student;

typedef struct node Node;

struct node{
    
    Student* s;
    Node* next;

};

Student* itoe(char* name, int ID){

    Student* s = (Student*)malloc(sizeof(Student));
    s->ID = ID;
    strcpy(s->name, name);

    return s;

}

int hash(int key,int size){
    
    int h1 = key%size;
    int h2 = key%256;
    int h3 = key%499;
    
    double A = 0.6180339887;
    double frac = key * A - (int)(key * A);
    int h4 = (int)(size * frac);

    int h5 = key%(443);
    int h6 = (key%499)%size;

    return h1;
}

int Insert(Node** hash_table, Student* s, int size){
    
    Node* n = (Node*)malloc(sizeof(Node));
    n->s = s;

    int index = hash(s->ID,size);
    
    if(hash_table[index] == NULL){
        hash_table[index] = n;
        return 0;
    }else{
        n->next = hash_table[index];
        hash_table[index] = n;
        return 1;
    }
    
}

void main(){

    FILE* fptr = fopen("t1_data.txt", "r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    char line[100];
    fgets(line,100,fptr);
    int size = atoi(line);

    Node* hash_table[2*size];

    for(int i = 0 ; i < 2*size ; i++){
        hash_table[i] = NULL;
    }

    int collision = 0;

    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        int ID = atoi(token);
        token = strtok(NULL,"\n");
        char name[30];
        strcpy(name,token);

        Student* s = itoe(name,ID);
        collision += Insert(hash_table,s,size);
    }

    printf("Total collisions : %d\n", collision);
}