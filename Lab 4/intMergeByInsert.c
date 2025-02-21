#include "intMerge.h"

void merge(int A[], int s, int mid, int e){
    
   for(int i = mid+1 ; i <= e ; i++){
        int val = A[i];
        int j = i-1;
        for(; j>=s ; j--){
            if(A[j] <= val) break;
            A[j+1] = A[j];
        }

        A[j+1] = val;
   }
}
