#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_static(int n) {
    int i, j;
    double sum = 0;
    static double arr[1024][1024]; // max size
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            arr[i][j] = (double) rand() / RAND_MAX;

    //row
    sum = 0;
    clock_t start = clock();
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            sum += arr[i][j];
    clock_t end = clock();
    printf("Static Row-Major n=%d sum=%lf time=%.6f s\n",
           n, sum, (double)(end - start) / CLOCKS_PER_SEC);

    //col
    sum = 0;
    start = clock();
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            sum += arr[i][j];
    end = clock();
    printf("Static Column-Major n=%d sum=%lf time=%.6f s\n",
           n, sum, (double)(end - start) / CLOCKS_PER_SEC);
}

void test_dynamic(int n) {
    int i, j;
    double sum = 0;
    double *arr = malloc(n * n * sizeof(double));
    if (!arr) {
        fprintf(stderr, "Failed to allocate %d x %d array\n", n, n);
        exit(1);
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            arr[i*n + j] = (double) rand() / RAND_MAX;

    //row
    sum = 0;
    clock_t start = clock();
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            sum += arr[i*n + j];
    clock_t end = clock();
    printf("Dynamic Row-Major n=%d sum=%lf time=%.6f s\n",
           n, sum, (double)(end - start) / CLOCKS_PER_SEC);
    //col
    sum = 0;
    start = clock();
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            sum += arr[i*n + j];
    end = clock();
    printf("Dynamic Column-Major n=%d sum=%lf time=%.6f s\n",
           n, sum, (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
}

int main() {
    int n = 128;
    while (n <= 1024) {
        test_static(n);
        test_dynamic(n);
        printf("\n");
        n *= 2;
    }
    return 0;
}
