#include <stdio.h>
#include "../Stack/stack.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

Element itoe (float i)
{
    Element e;
    e.int_value = 0;
    e.float_value = i;
    return e;
}

float operate(float a, float b, char s){
    switch (s){
        case '+' : return a+b;
        case '-' : return b-a;
        case '*' : return a*b;
        case '/' : return b/a;
    }

    return 0.0;
}

void main(){
    
    FILE* fptr = fopen("home_exercise2_input.txt","r");
    if(fptr == NULL){
        printf("Error opening file!");
        exit(0);
    }
    Stack* s = newStack();

    char input[100];
    fgets(input,100,fptr);
    char line[100];
    strcpy(line,input);
    char* token = strtok(input," ");
    
    while(token!= NULL){
        char c = token[0];
        
        if(isdigit(c)){
            push(s,itoe(c-'0'));
        }else{
            float a = top(s)->float_value;
            pop(s);
            float b = top(s)->float_value;
            pop(s);
            push(s,itoe(operate(a,b,c)));
        }
        token = strtok(NULL, " ");
    }

    printf("\nIf the input is %s then the result would be : %.2f\n", line, top(s)->float_value);

}