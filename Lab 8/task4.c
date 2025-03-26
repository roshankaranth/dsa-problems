#include<stdio.h>
#include<stdlib.h>

int* create4bitarray(int size){
    int filter_size = ((4*size) % (sizeof(int)*8)) == 0 ? ((4*size)/(sizeof(int)*8)) : (((4*size)/(sizeof(int)*8)) + 1);
    int* filter = (int*)malloc(sizeof(int)*filter_size);

    return filter;
}

int getCount(int *filter, int index){
        int i = (4*index) / ((sizeof(int)*8));
        int j = (4*index) % ((sizeof(int)*8));

        int counter = (filter[i]>>j) & 15;
        return counter;
}

void incrementIndex(int *filter, int index){
    int i = (4*index) / ((sizeof(int)*8));
    int j = (4*index) % ((sizeof(int)*8));

    int counter = (filter[i]>>j) & 15;
    if(counter == 15) return;
    counter += 1;

    filter[i] = filter[i] & (~(15<<j));
    filter[i] = filter[i] | (counter<<j);

}

void decrementIndex(int* filter, int index){
    int i = (4*index) / ((sizeof(int)*8));
    int j = (4*index) % ((sizeof(int)*8));
   
    int counter = (filter[i]>>j) & 15;
    if(counter == 0) return;
    counter -= 1;
    
    filter[i] = filter[i] & (~(15<<j));
    filter[i] = filter[i] | (counter<<j);
}

int main()
{
    int *array = create4bitarray(10);
    // Print the array
    for (int i = 0; i < 10; i++){
        printf("%d ", getCount(array, i));
    }
    
    printf("\n");
    
    incrementIndex(array, 0);
    incrementIndex(array, 5);
    incrementIndex(array, 5);
    incrementIndex(array, 0);
    incrementIndex(array, 9);
    // Print the array
    for (int i = 0; i < 10; i++){
        printf("%d ", getCount(array, i));
    }

    printf("\n");
    decrementIndex(array, 0);
    decrementIndex(array, 5);
    decrementIndex(array, 9);
    // Print the array
    for (int i = 0; i < 10; i++){
        printf("%d ", getCount(array, i));
    }

    printf("\n");
    incrementIndex(array, 3);
    incrementIndex(array, 3);
    incrementIndex(array, 0);
    incrementIndex(array, 0);
    incrementIndex(array, 0);
    incrementIndex(array, 0);
    incrementIndex(array, 0);
    incrementIndex(array, 1);
    incrementIndex(array, 2);

    for (int i = 0; i < 20; i++){
        incrementIndex(array, 8); // Should saturate at 15
    }

    for (int i = 0; i < 20; i++){
        decrementIndex(array, 1); // Should saturate at 0
    }
    // Print the array
    for (int i = 0; i < 10; i++){
        printf("%d ", getCount(array, i));
    }
    
    printf("\n");
    return 0;
}