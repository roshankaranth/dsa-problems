#include "personMergeAux.h"

void mergeAux(Person A[], int s1, int e1, Person B[], int s2, int e2, Person C[], int s3, int e3){

    int i = s1, j = s2, k = s3;
    while(i<=e1 && j<=e2){
        if(A[i].height > A[j].height){
            C[k] = A[j];
            j++;
        }else{
            C[k] = A[i];
            i++;
        }

        k++;
    }

    while(i<=e1){
        C[k] = A[i];
        k++;
        i++;
    }

    while(j<=e2){
        C[k] = A[j];
        k++;
        j++;
    }

}
