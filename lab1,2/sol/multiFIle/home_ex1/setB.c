#include "set.h"

int answer_checker(char* answers){
    char sol[] = {'D', 'C', 'B', 'A', 'D', 'C', 'A', 'B', 'D', 'C'};
    int score = 0;
    for(int i = 0 ; i < 10 ; i++ ){
        if(answers[i] == sol[i]) score+= 4;
        else if(answers[i] == 'N' ) score += 0;
        else if(score>0) score-=1;
    }

    return score;
}