#include <stdio.h>
#include <sys/time.h>
#include<stdlib.h>

void rowMajorMatixAdd(int n, int matrix1[n][n],int matrix2[n][n]){
    int res[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        
        }
    }
    
}

void colMajorMatixAdd(int n, int matrix1[n][n],int matrix2[n][n]){
    int res[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            res[j][i] = matrix1[j][i] + matrix2[j][i];
            
        }
    }
    
}

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int matrix1[n][n];
    int matrix2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    struct timeval t1, t2;
    double time_taken = 0;
    int res[n][n];

    gettimeofday(&t1,NULL);
    rowMajorMatixAdd(n,matrix1,matrix2);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken += (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("Row Major approach took %f seconds to execute", time_taken);

    gettimeofday(&t1,NULL);
    colMajorMatixAdd(n,matrix1,matrix2);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken += (t2.tv_usec-t1.tv_usec) * 1e-6;

    printf("\nColumn Major approach took %f seconds to execute\n", time_taken);

}