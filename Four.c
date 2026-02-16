#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdint.h>
int main(){
    //thousand multiplies
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);  
    volatile uint64_t a = 2;
    for(int i = 0;i<1000000;i++) {
        a *= 3;
    }
    QueryPerformanceCounter(&end);
    double elapsed = (double)((end.QuadPart - start.QuadPart) / (double)freq.QuadPart);
    printf("avg time mult: %f / 10^6 avg s val: %llu\n", elapsed, a);
    //thousand divides
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);  
    volatile double b = 0xFFFFFFFFFFFFFFFF;
    for(int i = 0;i<1000000;i++) {
        b /= 3;
    }
    QueryPerformanceCounter(&end);
    elapsed = (double)((end.QuadPart - start.QuadPart) / (double)freq.QuadPart);
    printf("avg time div: %f / 10^6 avg s val: %f\n", elapsed, b);
    //thousand square roots
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start); 
    volatile double c = 0xFFFFFFFFFFFFFFFF;
    for(int i = 0;i<1000000;i++) {
        c = sqrt(c);
    }
    QueryPerformanceCounter(&end);
    elapsed = (double)((end.QuadPart - start.QuadPart) / (double)freq.QuadPart);
    printf("avg time sqrt: %f / 10^6 avg s val: %f\n", elapsed, c);
    //thousand sines
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start); 
    volatile double d = 0xFFFFFFFFFFFFFFFF;
    for(int i = 0;i<1000000;i++) {
        d = sin(d);
    }
    QueryPerformanceCounter(&end);
    elapsed = (double)((end.QuadPart - start.QuadPart) / (double)freq.QuadPart);
    printf("avg time sin: %f / 10^6 avg s val: %f\n", elapsed, d);


}