#include <stdio.h>

void display(int* arr, int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d ", arr[i]);
    }
}

int partition(int* arr, int l, int r){
    int x = arr[r];
    int i = l-1;

    for(int j = l ; j <= r-1 ; j++){
        if(arr[j] < x){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[r];
    arr[r] = arr[i+1];
    arr[i+1] = temp;

    return i+1;
}

void quickSort(int* arr, int l, int r){
    if(l>r) return;

    int p = partition(arr,l,r);
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,r);
}

void main(){
   
    int arr[] = {88, 89, 84, 75, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 84, 70, 94, 69};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    
    display(arr,size);



}