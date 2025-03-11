#include<stdio.h>
#include<sys/time.h>

long long int factNTR(int n){
    if(n==1) return 1;

    return n*factNTR(n-1);
}

long long int factTR(int n, long long int acc){
    if(n==0) return acc;

    return factTR(n-1,acc*n);
}

long long int factIt(int n){
    long long int acc = 1;
    while(n>0){
        acc = acc*n;
        n=n-1;
    }

    return acc;
}


void main(){
    int n = 20;
    long long int acc = 1;
    long long int res = 0;

    struct timeval t1,t2;
    double time_taken = 0;

    gettimeofday(&t1,NULL);
    res = factNTR(n);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken = (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nFactorial calculated using the NTR function : %lld", res);
    printf("\nNTR approach took %f seconds to execute\n", time_taken);

    gettimeofday(&t1,NULL);
    res = factTR(n,acc);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken = (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nFactorial calculated using the TR function : %lld", res);
    printf("\nTR approach took %f seconds to execute\n", time_taken);

    gettimeofday(&t1,NULL);
    res = factIt(n);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken = (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nFactorial calculated using the iterative function : %lld", res);
    printf("\niterative approach took %f seconds to execute\n", time_taken);
}