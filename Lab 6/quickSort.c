#include <stdio.h>

void display(int* arr, int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d ", arr[i]);
    }
}

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int lomutoPartition(int* arr, int l, int r, int pv){
    swap(arr,pv,r);
    int x = arr[r];
    int i = l-1;

    for(int j = l ; j <= r-1 ; j++){
        if(arr[j] < x){
            i++;
            swap(arr,i,j);
        }
    }

    swap(arr,i+1,r);

    return i+1;
}

int twoWayHoarePartition(int *arr, int l, int r, int pv){
    swap(arr,pv,r);
    int i = l;
    int j = r-1;
    
    while(i<=j){
        while(i< r && arr[i] <= arr[r]) i++;
        while(j>=l && arr[j] > arr[r]) j--;
        if(i<j) swap(arr,i,j);        
    }

    swap(arr, i, r);

    return i;
}

int threeWayHoarePartition(int* arr, int l, int r, int pv){
    swap(arr,pv,r);
    int  i = l;
    int j = r-1;
    int mid = l;
    while(mid<=j){
        if(arr[mid] < arr[r]){
            swap(arr,mid,i);
            i++;
            mid++;
        }else if(arr[mid] > arr[r]){
            swap(arr,mid,j);
            j--;
        }else{
            mid++;
        }
    }

    swap(arr,mid,r);
    return mid;
}   

void quickSort(int* arr, int l, int r){
    if(l>=r) return;
    int pv = (l+r)/2;
    int p = threeWayHoarePartition(arr,l,r,pv);
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,r);
}

void main(){
   
    int arr[] = {88, 89, 84, 75, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 84, 70, 94, 69};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    
    display(arr,size);



}