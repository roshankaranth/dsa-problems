#include<stdio.h>

void displayArray(int A[],int size){
    for(int i = 0 ; i < size; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void Heapify(int A[], int i, int n){
    
        int left = 2*i;
        int right = 2*i + 1;
        int largest = i;

        if(left < n && A[left] > A[i]) largest = left;
        else largest = i;
        if(right < n && A[right] > A[largest]) largest = right;

        if(largest != i){
            int temp = A[largest];
            A[largest] = A[i];
            A[i] = temp;
            Heapify(A,largest,n);
        }
    
}

void buildMaxHeap(int A[], int n){
    
    for(int i = (n-1)/2 ; i>=0 ; i--){
        Heapify(A,i,n);
    }
}

void HeapSort(int A[], int size){
    buildMaxHeap(A, size);
    for(int i = size-1 ; i>=2 ; i--){
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        Heapify(A,0,i-1);
    }
}

void main(){
    int arr[] = {88, 89, 84, 75, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 84, 70, 94, 69};
    int size = sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr, size);

    displayArray(arr,size);
}

//heap sort is not stable sort