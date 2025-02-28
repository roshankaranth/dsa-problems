#include<stdio.h>

void swap(int arr[], int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void display(int arr[], int p, int r){
    for(int i = p ; i <= r ; i++ ){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int pivotSelection(int oarr[], int p, int r){
    int size = r-p+1;
    int arr[size];
    for(int i = 0 ; i < size; i++){
        arr[i] = oarr[p+i];
    }

    int groups = size/5;
    int groupMedians[groups];

    for(int k = 0 ; k < groups; k++){
        int p = k*5;
        for(int i = 1 ; i < 5 ; i++){
            int x = arr[p+i];
            int j = i-1;
            for(; j>=p ; j--){
                if(arr[p+j] > x) arr[p+j+1] = arr[p+j];
                else break;
            }

            arr[p+j+1] = x;
        }

        groupMedians[k] = arr[p+2];
    }

    for(int i = 1 ; i < groups ; i++){
        int x = groupMedians[i];
        int j = i-1;
        for(; j>=0 ; j--){
            if(groupMedians[j] > x) groupMedians[j+1] = groupMedians[j];
            else break;
        }

        groupMedians[j+1] = x;
    }

    for(int i = p ; p <= r ; i++){
        if(groupMedians[groups/2] = oarr[i]) return i;
    }

}

int partition(int arr[], int p, int r, int pv){
    swap(arr,pv,r);

    int i = p-1;
    int j = p;

   for(;j<r ;j++){
        if(arr[j] <= arr[r]){
            i++;
            swap(arr,i,j);
        }
   }

   swap(arr,i+1,r);

   //display(arr,p,r);

   return i+1;
}

int quickSelect(int arr[], int p, int r, int k ){
    //printf("%d %d\n", p,r);
    if(p>r) return 0;

    int pv = pivotSelection(arr,p,r);
    //int pv = (p+r)/2;

    //printf("pivot %d : " , arr[pv]);
    int pInd = partition(arr,p,r,pv);

    if(k-1 == pInd) return arr[pInd];
    if(pInd > k-1) quickSelect(arr,p,pInd-1,k);
    else quickSelect(arr,pInd+1,r,k);
}


void main(){
    //1 2 3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20
    //4 5 13 22 24 30 35 39 53 64 69 70 75 77 84 84 88 89 94 100 
    int arr[] = {88, 89, 84, 75, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 84, 70, 94, 69};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 15;
    int ele = quickSelect(arr,0, size-1 ,k);
    printf("Element at rank %d is : %d\n",k, ele);
}