#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOOM_FILTER_SIZE 256

int* createBloomFilter(int size){
    int filter_size = ((4*size) % (sizeof(int)*8)) == 0 ? ((4*size)/(sizeof(int)*8)) : (((4*size)/(sizeof(int)*8)) + 1);
    int* filter = (int*)malloc(sizeof(int)*filter_size);

    return filter;
}

void incrementIndex(int *filter, int index){
    int i = (4*index) / ((sizeof(int)*8));
    int j = (4*index) % ((sizeof(int)*8));

    int counter = (filter[i]>>j) & 15;
    if(counter == 15) return;
    counter += 1;

    filter[i] = filter[i] & (~(15<<j));
    filter[i] = filter[i] | (counter<<j);

}

void decrementIndex(int* filter, int index){
    int i = (4*index) / ((sizeof(int)*8));
    int j = (4*index) % ((sizeof(int)*8));
   
    int counter = (filter[i]>>j) & 15;
    if(counter == 0) return;
    counter -= 1;
    
    filter[i] = filter[i] & (~(15<<j));
    filter[i] = filter[i] | (counter<<j);
}

void setCount(int* filter, int key){

    int h1 = key%256;

    // double A = 0.6180339887;
    // double frac = key*A - (int)(key*A);
    // int h2 = (int)(256*frac);

    // int h3 = key%43;
    // int h4 = (key ^ (key>>3))%256;
    // int h5 = 255 - (key%197);

    incrementIndex(filter, h1);
    // incrementIndex(filter, h2);
    // incrementIndex(filter, h3);
    // incrementIndex(filter, h4);
    // incrementIndex(filter, h5);
}

void clearCount(int* filter,  int key){
    int h1 = key%256;

    // double A = 0.6180339887;
    // double frac = key*A - (int)(key*A);
    // int h2 = (int)(256*frac);

    // int h3 = key%43;
    // int h4 = (key ^ (key>>3))%256;
    // int h5 = 255 - (key%197);

    decrementIndex(filter, h1);
    // decrementIndex(filter, h2);
    // decrementIndex(filter, h3);
    // decrementIndex(filter, h4);
    // decrementIndex(filter, h5);
}

int getCount(int *filter, int index){
    int i = (4*index) / ((sizeof(int)*8));
    int j = (4*index) % ((sizeof(int)*8));

    int counter = (filter[i]>>j) & 15;
    return counter;
}

int checkCount(int *filter, int key){
    int h1 = key%256;

    // double A = 0.6180339887;
    // double frac = key*A - (int)(key*A);
    // int h2 = (int)(256*frac);

    // int h3 = key%43;
    // int h4 = (key ^ (key>>3))%256;
    // int h5 = 255 - (key%197);

    int r1 = (getCount(filter, h1) == 0) ?0 : 1;
    // int r2 = getCount(filter, h2);
    // int r3 = getCount(filter, h3);
    // int r4 = getCount(filter, h4);
    // int r5 = getCount(filter, h5);

    return r1;
}

void main(){

    int* filter = createBloomFilter(BLOOM_FILTER_SIZE);
    
    FILE* fptr = fopen("bloom_numbers.txt","r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    char line[100];
    while(fgets(line,100,fptr)){
        int key = atoi(line);
        setCount(filter, key);
    }

    fclose(fptr);

    int present = 0;
    int absent = 0;

    fptr = fopen("count_bloom_queries.txt","r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }



    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        int operation = atoi(token);
        token = strtok(NULL,"");
        int key = atoi(token);

        switch(operation) {
            case 1 : setCount(filter,key);
                     break;
            case 2 : clearCount(filter,key);
                     break;
            case 3 : if(checkCount(filter,key)) present++;
                     else absent++;
                     break;
        }

    }

    printf("Present keys : %d, Absent keys : %d\nfalse positives = %d\n", present, absent,20-absent);
}