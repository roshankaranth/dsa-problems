#include <stdio.h>
#include <sys/time.h>
#include<stdlib.h>

void IterInsertionSort(int arr[], int size){

    for(int i = 1 ; i < size ; i++){
        int last = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j] > last){
                arr[j+1] = arr[j];
            }else break;

            j--;
        }
        
        arr[j+1] = last;
    }

}

void RecurInsertionSort(int arr[], int size){
    if(size == 1) return;
    RecurInsertionSort(arr,size-1);

    int last = arr[size-1];
    int j = size - 2;
    while(j>=0){
        if(arr[j] > last){
            arr[j+1] = arr[j];
        }else break;

        j--;
    }

    arr[j+1] = last;
    
}

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    int size = atoi(argv[2]);
    int numbers1[size];
    int numbers2[size];
    int i = 0;
    while (fscanf(fp, "%d", &numbers1[i]) != EOF)
    {
        numbers2[i] = numbers1[i];
        i++;
    }
    fclose(fp);

    struct timeval t1,t2;
    double time_interval = 0;

    gettimeofday(&t1,NULL);
    IterInsertionSort(numbers1, size);
    gettimeofday(&t2,NULL);

    // printf("\n");
    // for(int i = 0 ; i < size ; i++){
    //     printf("%d ", numbers1[i]);
    // }
    // printf("\n");

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec - t1.tv_usec) * 1e-6;

    printf("Iterative approach took %f seconds to execute!", time_interval);

    gettimeofday(&t1,NULL);
    RecurInsertionSort(numbers2, size);
    gettimeofday(&t2,NULL);

    // printf("\n");  
    // for(int i = 0 ; i < size ; i++){
    //     printf("%d ", numbers2[i]);
    // }
    // printf("\n");

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec - t1.tv_usec) * 1e-6;

    printf("\nRecursive approach took %f seconds to execute!", time_interval);

}