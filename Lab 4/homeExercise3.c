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
    int A[] = {-1,0,1,2,-1,-1};
    //int A[] = {0,1,1};
    
    int size = sizeof(A)/sizeof(int);
    mergeSort(A,0, size-1);

    for(int i = 0 ; i < size ; i++){
        if(i!=0 && A[i] == A[i-1]) continue;
        int num = A[i];
        int j = i+1;
        int k = size-1;
        while(j<k){
            if(A[i] + A[j] + A[k] == 0){
                printf("%d %d %d\n", A[i], A[j], A[k]);
                j++;
                while(A[j-1] == A[j]) j++;
            }else if(A[i] + A[j] + A[k] > 0) k--;
            else j++;
        }

    }
    
}