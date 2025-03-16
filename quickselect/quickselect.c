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

int min(int l, int r){
    if(l>r) return r;
    else return l;
}

int pivotSelection(int oarr[], int p, int r){
    
    int size = r-p+1;

    if(size <= 5){

        int temp[size];
        for(int i = 0 ; i < size ; i++){
            temp[i] = oarr[p + i];
        }

        for(int i = 1 ; i < size ; i++){
            int x = temp[i];
            int j = i - 1;
            while(j>=0){
                if(temp[j] > x) temp[j+1] = temp[j];
                else break;

                j--;
            }

            temp[j+1] = x;
        }

        for(int i = p ; i <= r ; i++){
            if(oarr[i] == temp[size / 2]) return i;
        }

    }

    int groupMedians = 0;
    if(size % 5 == 0) groupMedians = size / 5;
    else groupMedians = (size/5) + 1;

    int Medians[groupMedians];

    for(int i = 0 ; i < groupMedians ; i++){
        Medians[i] = oarr[pivotSelection(oarr, p + i*5, min(r,p + i*5 + 4))];
    }

    int x = pivotSelection(Medians, 0, groupMedians-1);

    for(int i = p ; i <= r ; i++){
        if(oarr[i] == Medians[x]) return i;
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
    int k = 12;
    int ele = quickSelect(arr,0, size-1 ,k);
    printf("Element at rank %d is : %d\n",k, ele);
}