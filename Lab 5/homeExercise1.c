#include<stdio.h>
#include<sys/time.h>


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

void mergeSortRec(int A[], int s, int e){
    if(s==e) return;

    int mid = (s+e)/2;

    mergeSortRec(A,s,mid);
    mergeSortRec(A,mid+1,e);
    merge(A,s,mid,e);

}

void mergeSortIter(int A[], int s, int e){
    int curr_size; 
    int left_start; 
    int n = e-s+1;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n) ? left_start + 2 * curr_size - 1 : n - 1;

            merge(A, left_start, mid, right_end);
        }
    }

}



int main(){
    int A[] = {88, 89, 84, 75, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87, 30, 4, 64, 39, 5, 13, 35, 22, 100, 77, 24, 53, 70, 94, 69, 87};

    struct timeval t1,t2;
    double time_taken = 0;
    
    gettimeofday(&t1,NULL);
    mergeSortRec(A,0,sizeof(A)/sizeof(int)-1);
    gettimeofday(&t2,NULL);

    // for(int i = 0 ; i < sizeof(A)/sizeof(int); i++){
    //     printf("%d ", A[i]);
    // }

    time_taken = (t2.tv_sec - t1.tv_sec)*1e6;
    time_taken += (t2.tv_usec-t1.tv_usec)*1e-6;

    printf("Recursive approach took %f seconds to execute!", time_taken);

    gettimeofday(&t1,NULL);
    mergeSortIter(A,0,sizeof(A)/sizeof(int)-1);
    gettimeofday(&t2,NULL);

    // for(int i = 0 ; i < sizeof(A)/sizeof(int); i++){
    //     printf("%d ", A[i]);
    // }

    time_taken = (t2.tv_sec - t1.tv_sec)*1e6;
    time_taken += (t2.tv_usec-t1.tv_usec)*1e-6;

    printf("\nIterative approach took %f seconds to execute!\n", time_taken);


}