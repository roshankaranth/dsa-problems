#include <stdio.h>

void merge(int A[], int s, int mid, int e){

    for(int i = mid+1 ; i <= e ; i++){
        int ele = A[i];
        int j = i-1;
        while(j>=s){
            if(A[j]<=ele) break;
            A[j+1] = A[j];
            j--;
            
        }

        A[j+1] = ele;
    }
}

void mergeSort(int A[],int s, int e){
    if(s==e) return;

    int mid = (s+e)/2;
    mergeSort(A,s,mid);
    mergeSort(A,mid+1,e);
    merge(A,s,mid,e);
}

int main(){
    int A[] = {3,2,1,3};
    //int A[] = {1,1,3,3};
    int size = sizeof(A)/sizeof(int);
    mergeSort(A,0, size-1);
    int flag = 0;
    for(int i = 0 ; i < size ; i++){
        if(A[i] == (size-i-1)){
            printf("%d ", A[i]);
            return 0;
        }
    }

    printf("No such integer found!\n");
}