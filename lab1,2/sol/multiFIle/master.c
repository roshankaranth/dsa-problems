#include<stdio.h>
#include "count.h"

int main(void) {
    
    char s[100];
    printf("Enter a string : ");
    scanf("%[^\n]s", s);

    int n = count(s);
    printf("Count = %d" , n);
}

//what is actually there in object files ?
//what's the point of .h files ? why not include the .c files ?
