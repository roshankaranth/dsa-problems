#include "personMerge.h"
#include <stdlib.h>

void merge(Person A[], int s, int mid, int e){
       
    Person* C = (Person*)malloc(sizeof(Person)*(e-s+1));
    mergeAux(A,s,mid,A,mid+1,e,C,0,e-s);
    
    for(int i = 0 ; i < e-s+1 ; i++){
        A[s+i] = C[i];
    }

    free(C);
}