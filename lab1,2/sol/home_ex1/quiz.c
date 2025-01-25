#include "set.h"
#include <stdio.h>

void main(void) {
    char ans[10];

    printf("Enter your answers : ");
    for(int i = 0 ; i < 10 ; i++){
        scanf(" %c", &ans[i]);

    }

    int score = answer_checker(ans);
    printf("Score  : %d \n", score );

}
