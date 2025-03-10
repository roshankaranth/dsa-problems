#include<stdio.h>
#include<sys/time.h>

long long int recursiveFibo(int n){
    if(n==1) return 1;
    else if(n==0) return 0;
    
    return recursiveFibo(n-1) + recursiveFibo(n-2);
}

void main(){
    
    
    int n = 50;
    long long int res = 0;

    struct timeval t1, t2;
    double time_interval = 0;

    gettimeofday(&t1,NULL);
    res = recursiveFibo(n);
    gettimeofday(&t2,NULL);

    printf("The %d number in Fibonacchi series is : %lld\n", n, res);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec - t1.tv_usec) * 1e-6;

    printf("Recursive Fibonacchi seq took %f seconds to execute.\n\n", time_interval);

    long long int i = 1;
    long long int j = 1;

    gettimeofday(&t1,NULL);
    
    for(int k = 3 ; k <= n ; k++ ){
        res = i+j;
        j = i;
        i = res;
    }
    gettimeofday(&t2,NULL);

    printf("The %d number in Fibonacchi series is : %lld\n", n, res);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec - t1.tv_usec) * 1e-6;

    printf("Iterative Fibonacchi seq took %f seconds to execute.\n", time_interval);

}