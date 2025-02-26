#include<stdio.h>

void lumotoPartition(int* arr, int size){
    int j = 0;
    int i = -1;

    while(j<size){
        while(j<size && arr[j] > 0) j++;

        if(j<size){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

void twoWayHoarePartition(int* arr, int size){
    int j = size-1;
    int i = 0;

    while(i<=j){
        while(i<size && arr[i]<=0) i++;
        while(j>=0 && arr[j]>0) j--;

        if(i<=j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }
}

void main(){
    int arr[] = {0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,0,0,0,1,0,0,1,1};

    int size = sizeof(arr)/sizeof(arr[0]);
    lumotoPartition(arr,size);
    //twoWayHoarePartition(arr,size);

    for(int i = 0 ; i < size ; i++){
        printf("%d ", arr[i]);
    }
}