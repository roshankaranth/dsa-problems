#include <stdio.h>
#include <sys/time.h>
#include<stdlib.h>

void matrix_multiply_iterative(int size, int c[size][size],int d[size][size],int new[size][size]){

    for(int k = 0 ; k < size; k++){
        for(int i = 0 ; i < size ; i++){
            new[k][i] = 0;
            for(int j = 0 ; j < size ; j++){
                new[k][i] += c[k][j]*d[j][i];
            }
        }
    }
}

void print_matrix(int size, int matrix[size][size]){
    printf("\n");
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
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

    struct timeval t1,t2;
    double time_taken = 0;
    int res[n][n];
    gettimeofday(&t1,NULL);
    matrix_multiply_iterative(n,matrix1, matrix2,res);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec);
    time_taken += (t2.tv_usec - t2.tv_usec) * 1e-6;

    print_matrix(n,res);
    printf("\n");
    printf("Iterative approach took %f time to execute.\n", time_taken);

    // gettimeofday(&t1,NULL);
    // matrix_multiply_iterative();
    // gettimeofday(&t2,NULL);

    // time_taken = (t2.tv_sec - t1.tv_sec);
    // time_taken += (t2.tv_usec - t2.tv_usec) * 1e-6;

    // printf("Recursive approach took %f time to execute.\n", time_taken);

    // gettimeofday(&t1,NULL);
    // matrix_multiply_iterative();
    // gettimeofday(&t2,NULL);

    // time_taken = (t2.tv_sec - t1.tv_sec);
    // time_taken += (t2.tv_usec - t2.tv_usec) * 1e-6;

    // printf("Recursive(Strassen's) approach took %f time to execute.\n", time_taken);


}