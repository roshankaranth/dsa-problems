#include <stdio.h>
#include "intMerge.h"
#include "intMergeAux.h"

void mergeSort(int A[], int s, int e){
    if(s==e) return;

    int mid = (s+e)/2;

    mergeSort(A,s,mid);
    mergeSort(A,mid+1,e);
    merge(A,s,mid,e);

}

int main(){
    int A[] = {88, 89, 84, 75, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87};

    mergeSort(A,0,sizeof(A)/sizeof(int)-1);
    for(int i = 0 ; i < sizeof(A)/sizeof(int); i++){
        printf("%d ", A[i]);
    }
}

