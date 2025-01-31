#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main(void){

    FILE* fp = fopen("../../LOTR.txt","r");

    if(fp==NULL){
        printf("Couldn't open file!\n");
        exit(1);
    }

    char line[500];
    int count = 0;
    
    while(fgets(line,500,fp)){
        for(int i = 0 ;line[i]; i++){
            line[i] = tolower(line[i]);
            if(ispunct(line[i])) line[i] = ' ';
        }
        char *token = strtok(line, " ");
        while(token != NULL){
            
            if(!strcmp(token, "hobbit")) count++;
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);
    printf("Count of hobbit : %d\n", count);

}