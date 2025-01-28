#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct name{
    char firstname[20];
    char lastname[20];
}Name;

void main(void) {
    
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    Name* arr = (Name*)calloc(n,sizeof(Name));

    printf("Enter names one by one : \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%s %s", arr[i].firstname, arr[i].lastname);
    }

    printf("\nEntered name :\n" );
    for(int i = 0 ; i < n ; i++){
       printf("%s %s \n", arr[i].firstname, arr[i].lastname);
    }


    while(1){
        printf("\nSelect one of the options :\n"
        "(a) Add a string to the end of the array,\n"
        "(b) Add a string to the beginning of the array,\n"
        "(c) Delete the element at index 'x' (taken as input) of the array,\n"
        "(d) Display the length of the array,\n"
        "(e) Display all the elements of the array in sequence.\n"
        "(f) Exit menu\n"
        "(pick from one of the options form (a-f)");

        char opt;
        scanf(" %c", &opt);

        switch (opt){
            case 'a' : arr = realloc(arr, (n+1)*sizeof(Name));
                             printf("\nEnter another name : \n");
                             scanf("%s %s", arr[n].firstname, arr[n].lastname);
                             n = n+1;
                             break;
            
            case 'b' : n++;
                       arr = realloc(arr,sizeof(Name)*(n));
                       for(int i = n-1 ; i >= 0 ; i--){
                            strcpy(arr[i+1].firstname, arr[i].firstname);
                            strcpy(arr[i+1].lastname, arr[i].lastname);
                       }
                       printf("\nEnter another name : \n");
                       scanf("%s %s", arr[0].firstname, arr[0].lastname);
                       break;
            
            case 'c' : printf("\nEnter the index of element to be deleted : ");
                       int x = 0;
                       scanf(" %d", &x);
                       for(int i = x+1 ; i < n ; i++){
                         strcpy(arr[i-1].firstname,arr[i].firstname);
                         strcpy(arr[i-1].lastname, arr[i].lastname);
                       }
                       n--;
                       arr = (Name*)realloc(arr, sizeof(Name)*(n)); 
                       break;

            case 'd' : printf("\nSize of array : %d", n);
                       break;

            case 'e' : printf("\nArray elements: \n");
                       for(int i = 0 ; i < n ; i++){
                            printf("%s %s \n", arr[i].firstname, arr[i].lastname);
                       }
                       break;
            case 'f' : exit(0);

        }
    }
}

//what does typedef do ?