#include <stdio.h>
#include <omp.h>
#define NX 102400

int main(void)
{
    long vecA[NX];
    long sum, psum, sumex;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i+1;
    }

    sum = 0.0;
    /* TODO: Parallelize computation */

#pragma omp parallel shared(vecA,sum)
{
#pragma omp for schedule(static) reduction(+:sum)

    for (i = 0; i < NX; i++) {
        sum += vecA[i];
    }
}
    printf("Sum: %ld\n",sum);



    return 0;
}
