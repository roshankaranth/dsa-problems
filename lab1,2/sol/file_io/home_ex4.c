#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(void) {
    FILE* fp;
    fp = fopen("../../msg.txt","r");

    if(fp==NULL){
        printf("Error opening file!");
        exit(1);
    }

    char line[500];
    fgets(line,500,fp);
    char* morse_alpha[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char* morse_num[] = {"-----",".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    char res[100];
    int j = 0;
    char* token = strtok(line," ");
    while(token!=NULL){

            if(!strcmp(token,"/")){
                res[j] = ' ';
                j++;
            }

            for(int i = 0 ; i < 26; i++){
                if(!strcmp(token,morse_alpha[i])){
                    res[j] = (char)(65+i);
                    j++;
                    break;
                }
            }

            for(int i = 0 ; i < 10; i++){
                if(!strcmp(token,morse_num[i])){
                    res[j] = (char)(48+i);
                    j++;
                    break;
                }
            }
            token = strtok(NULL," ");
        }

    printf("%s\n",res);

}