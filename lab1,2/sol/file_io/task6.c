#include<stdio.h>
#include<stdlib.h>

void main(){

    FILE* ptr1 = fopen("test1.txt", "r");
    FILE* ptr2 = fopen("test2.txt", "w");

    if(ptr1==NULL || ptr2==NULL){
        printf("Error opening file!");
        exit(1);
    }

    char line[100];
    while(fgets(line,100,ptr1)){
        fputs(line,ptr2);
    }

    fclose(ptr1);
    fclose(ptr2);

    ptr1 = fopen("test1.txt", "w");
    fclose(ptr1);


}