#include<stdio.h>
#include<stdlib.h>

void main(void) {
    
    FILE* fp = fopen(__FILE__, "r");

    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    char line[100];
    while(fgets(line,100,fp)){
        printf("%s",line);
    }

    fclose(fp);
}