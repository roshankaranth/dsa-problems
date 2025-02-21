#include <stdio.h>
#include "intMerge.h"
#include "intMergeAux.h"
#include <sys/time.h>
#include "heap_usage.h"

void mergeSort(int A[], int s, int e){
    if(s==e) return;

    int mid = (s+e)/2;

    mergeSort(A,s,mid);
    mergeSort(A,mid+1,e);
    merge(A,s,mid,e);

}

int main(){
    int A[] = {88, 89, 84, 75, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87};

    struct timeval t1,t2;
    double time_taken = 0;
    
    gettimeofday(&t1,NULL);
    mergeSort(A,0,sizeof(A)/sizeof(int)-1);
    gettimeofday(&t2,NULL);

    for(int i = 0 ; i < sizeof(A)/sizeof(int); i++){
        printf("%d ", A[i]);
    }

    time_taken = (t2.tv_sec - t1.tv_sec)*1e6;
    time_taken += (t2.tv_usec-t1.tv_usec)*1e-6;

    printf("\nTime Taken for sorting : %f", time_taken);
    printf("\nTotal Heap Memory Allocated : %ld\n", totalHeapMemoryAllocated);


}

