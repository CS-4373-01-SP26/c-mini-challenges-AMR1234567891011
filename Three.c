#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 10

int main() {
    FILE *fp = fopen("mv.txt", "r");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }
    int matrix[N][N];
    int vector[N];
    int result[N] = {0};
    int temp = 0;
    fscanf(fp, "%d %d", &temp, &temp);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
            }
        }
    fscanf(fp, "%d", &temp);
    for (int i = 0; i < N; i++) {
        fscanf(fp, "%d", &vector[i]);
    }
    fclose(fp);
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);  
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j] * vector[j];
        }
        result[i] = sum;
    }
    QueryPerformanceCounter(&end);
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    printf("Elapsed time: %f seconds\n", elapsed);
    printf("Result vector:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}
