#include <stdio.h>
#include <math.h>
#include <windows.h>
int main() {
    double d_sq = 2.0; //sidelen of square
    int sides = 4;//start at square
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);  
    while(sides < 129) {
        double out = sides * sqrt(d_sq / 4);
        printf("estimate %d: %f\n", sides, out);
        d_sq = 2 - 2 * sqrt(1 - d_sq / 4);
        sides *= 2;
    }
    QueryPerformanceCounter(&end);
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    printf("Elapsed time: %f seconds\n", elapsed);
    return 0;
}