#include<stdio.h>
#include<stdlib.h>

#define BLOOM_FILTER_SIZE 256

int* createBloomFilter(int size){
    
    int filter_size = ((size % (8*sizeof(int))) == 0) ? size / (8*sizeof(int)) : (size / (8*sizeof(int))) + 1;

    int* filter = (int*)malloc(sizeof(int)*filter_size);
    for(int i = 0 ; i < filter_size; i++){
        filter[i] = 0;
    }

    return filter;
} 

void setBitAux(int* filter, int index){
    int j = index/(sizeof(int)*8);
    int k = index%(sizeof(int)*8);

    filter[j] = filter[j] | (1<<k);
}

void setBit(int* filter, int key){

    int h1 = key%256;

    double A = 0.6180339887;
    double frac = key*A - (int)(key*A);
    int h2 = (int)(256*frac);

    int h3 = key%43;
    int h4 = (key ^ (key>>3))%256;
    int h5 = 255 - (key%197);

    setBitAux(filter, h1);
    setBitAux(filter, h2);
    setBitAux(filter, h3);
    setBitAux(filter, h4);
    setBitAux(filter, h5);
}

int checkBitAux(int* filter, int index){
    int j = index/(sizeof(int)*8);
    int k = index%(sizeof(int)*8);

    return (filter[j]>>k) & 1;
}

int checkBit(int *filter, int key){
    int h1 = key%256;

    double A = 0.6180339887;
    double frac = key*A - (int)(key*A);
    int h2 = (int)(256*frac);

    int h3 = key%43;
    int h4 = (key ^ (key>>3))%256;
    int h5 = 255 - (key%197);

    int r1 = checkBitAux(filter, h1);
    int r2 = checkBitAux(filter, h2);
    int r3 = checkBitAux(filter, h3);
    int r4 = checkBitAux(filter, h4);
    int r5 = checkBitAux(filter, h5);

    return r1 & r2 & r3 & r4 & r5;
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
        setBit(filter, key);
    }

    fclose(fptr);

    int present = 0;
    int absent = 0;

    fptr = fopen("bloom_queries.txt","r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    while(fgets(line,100,fptr)){
        int key = atoi(line);
        
        int res = checkBit(filter,key);
        if(res) present++;
        else absent++;
    }

    printf("Present keys : %d, Absent keys : %d\nfalse positives = %d\n", present, absent,52-absent);;
}