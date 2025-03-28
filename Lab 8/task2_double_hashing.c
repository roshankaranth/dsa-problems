#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASH_TABLE_SIZE 1024

typedef enum state {filled,empty,deleted}State;
typedef enum bool {false,true}bool;

int iop = 0;
int dop = 0;
int sop = 0;

int icol = 0;
int dcol = 0;
int scol = 0;

typedef struct student{
    long long int ID;
    char name[30];
}Student;

typedef struct hash_table_element{
    Student* s;
    State st;
}hash_table_element;

Student* itoe(char* name, long long int ID){
    
    Student* temp = (Student*)malloc(sizeof(Student));
    temp->ID = ID;
    strcpy(temp->name,name);

    return temp;

}

int hash_function(long long int key, int i, int m){
    double A = 0.6180339887;
    double frac = key * A - (int)(key * A);
    
    return ((int)(HASH_TABLE_SIZE * frac) + i*(1+(key%(HASH_TABLE_SIZE-1)))) % m;
}

void insert(Student* student, hash_table_element* hash_table){

    int index = hash_function(student->ID,0,HASH_TABLE_SIZE);

    if(hash_table[index].st != filled){
        hash_table[index].s = student;
        hash_table[index].st = filled;
        return;
    }else{
        int i = 1;
        if(i==1) icol++;
        int nindex = hash_function(student->ID, i, HASH_TABLE_SIZE);
        while(hash_table[nindex].st == filled && nindex != index) {
            i++;
            nindex = hash_function(student->ID, i, HASH_TABLE_SIZE);
        }

        if(nindex == index) return;

        hash_table[nindex].s = student;
        hash_table[nindex].st = filled;
        return;
    }
}

Student* search(hash_table_element* hash_table, int ID){
    
    for(int i = 0 ; i < HASH_TABLE_SIZE ; i++){
        if(i==1) scol++;
        int index = hash_function(ID,i,HASH_TABLE_SIZE);
        if(hash_table[index].st == empty){
            printf("%d not found!\n",ID);
            return NULL;
        }

        if(hash_table[index].st == filled && hash_table[index].s->ID == ID) return hash_table[index].s;
    }

    printf("%d not found!\n",ID);
    return NULL;
}

void delete(hash_table_element* hash_table, int ID){
    
    for(int i = 0 ; i < HASH_TABLE_SIZE ; i++){
        if(i==1) dcol++;
        int index = hash_function(ID,i,HASH_TABLE_SIZE);
        if(hash_table[index].st == empty){
            printf("%d not found!\n",ID);
            return;
        }

        if(hash_table[index].st == filled && hash_table[index].s->ID == ID){
            hash_table[index].st = deleted;
            printf("deleted %d\n", ID);
            return;
        }
    }

    printf("%d not found!\n",ID);
    return;
}

void main(){

    hash_table_element* hash_table = (hash_table_element*)malloc(sizeof(hash_table_element)*HASH_TABLE_SIZE);

    for(int i = 0 ; i < HASH_TABLE_SIZE ; i++){
        hash_table[i].st = empty;
        hash_table[i].s = NULL;
    }

    FILE* fptr = fopen("t1_data.txt","r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    char line[100];
    fgets(line,100,fptr);

    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        long long int ID = atoi(token);
        token = strtok(NULL,"\n");
        char name[30];
        strcpy(name,token);

        Student* element = itoe(name,ID);
        insert(element,hash_table);
    }

    fclose(fptr);

    fptr = fopen("t1_queries.txt","r");
    if(fptr == NULL){
        printf("error opening file!");
        return;
    }

    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        int operation = atoi(token);
        int ID;
        switch(operation){
            case 1 : token = strtok(NULL,",");
                     ID = atoi(token);
                     char name[30];
                     token = strtok(NULL,"\n");
                     strcpy(name,token);
                     Student* element = itoe(name,ID);
                     insert(element,hash_table);
                     printf("inserted %d %s\n", ID,name);
                     iop++;
                     break;
            
            case 2 : token = strtok(NULL," ");
                     ID = atoi(token);

                     delete(hash_table,ID);
                     dop++;
                     break;

            case 3 : token = strtok(NULL," ");
                     ID = atoi(token);

                     Student* s = search(hash_table,ID);
                     if(s!=NULL){
                        printf("Searched element : %s %lld\n",s->name,s->ID);
                     }
                     sop++;
                     break;
        }
    }

    printf("average collision during insertion : %f\n", (double)(icol)/iop);
    printf("average collision during delete : %f\n", (double)(dcol)/dop);
    printf("average collision during search : %f\n", (double)(scol)/sop);
    

}