#include<stdio.h>
#include<sys/time.h>

int lengthNTR(char *str){
    if(*str == '\0') return 0;

    return 1 + lengthNTR(str + 1);
}

int lengthTR(char *str, int len){
    if(*str == '\0') return len;

    return lengthTR(str + 1, len + 1);
}

int lengthI(char *str){
    int len = 0;
    while(*str != '\0'){
        len+=1;
        str+=1;
    }

    return len;
}

void main(){
    char* str = "Note that with enough practice, it becomes easier to convert a NTR function directly to aniterative function, without going through the intermediary TR function, by merely observing.However, to get to that stage we must first familiarize ourselves with the standard procedurethat we have discussed above and then get enough practice with the same.";

    struct timeval t1,t2;
    double time_taken = 0;
    long long  res = 0;

    gettimeofday(&t1,NULL);
    res = lengthNTR(str);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken += (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nLength calculated using the NTR function : %lld", res);
    printf("\nNTR approach took %f seconds to execute\n", time_taken);

    gettimeofday(&t1,NULL);
    res = lengthTR(str,0);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken += (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nLength calculated using the TR function : %lld", res);
    printf("\nNTR approach took %f seconds to execute\n", time_taken);

    gettimeofday(&t1,NULL);
    res = lengthI(str);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken += (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nLength calculated using the I function : %lld", res);
    printf("\nNTR approach took %f seconds to execute\n", time_taken);
}