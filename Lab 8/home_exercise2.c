#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASH_TABLE_SIZE 50

typedef enum state {filled,empty,deleted}State;
typedef enum bool {false,true}bool;

typedef struct hash_table_element{
    char keyword[30];
    State st;
}hash_table_element;

int hash_function(char* skey, int i, int m){

    int power = 1;
    int key = 0;
    for(int i = 0 ; skey[i] != '\0'; i++){
        key += (int)skey[i]*(power) % m;
        power *= 128;
    }
    double A = 0.6180339887;
    double frac = key * A - (int)(key * A);
    
    return ((int)(HASH_TABLE_SIZE * frac) + i*(1+(key%(HASH_TABLE_SIZE-1)))) % m;
}

void insert(char* keyword, hash_table_element* hash_table){
    for(int i = 0 ; i < HASH_TABLE_SIZE ; i++){
        int index = hash_function(keyword,i,HASH_TABLE_SIZE);
        if(hash_table[index].st != filled){
            strcpy(hash_table[index].keyword,keyword);
            hash_table[index].st = filled;
            return;
        }
    }

    printf("Hashtable full!\n");
    return;
}

bool valid_identifier(char* indentifier, hash_table_element* hash_table){
    
    for(int i = 0 ; i < HASH_TABLE_SIZE ; i++){
        
        int index = hash_function(indentifier,i,HASH_TABLE_SIZE);
        if(hash_table[index].st == empty){
            return true;
        }

        if(hash_table[index].st == filled && !strcmp(hash_table[index].keyword,indentifier)){
            
            return false;
        }
    }

    return true;
}

void main(){

    hash_table_element* hash_table = (hash_table_element*)malloc(sizeof(hash_table_element)*HASH_TABLE_SIZE);

    for(int i = 0 ; i < HASH_TABLE_SIZE ; i++){
        hash_table[i].st = empty;
    }

    FILE* fptr = fopen("keywords.txt","r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    char line[100];

    while(fgets(line,100,fptr)){
        char* token = strtok(line,"\n");
        char keyword[30];
        strcpy(keyword,token);

        insert(keyword,hash_table);
    }

    for(int i = 0 ; i < HASH_TABLE_SIZE ; i++){
        printf("%d %s \n",i,hash_table[i].keyword);
    }

    fclose(fptr);
    printf("\nEnter indentifier : ");
    scanf("%s",line);

    bool res = valid_identifier(line,hash_table);
    if(res==true) printf("Valid indentifier\n");
    else printf("Not a valid indentifier\n");

}