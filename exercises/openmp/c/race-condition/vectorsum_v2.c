#include <stdio.h>
#include <omp.h>
#define NX 102400


int main(void)
{
    long vecA[NX];
    long sum, psum, sumex, total;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i+1;
    }

    sum = 0.0;
    total = 0.0;
    /* TODO: Parallelize computation */

#pragma omp parallel shared(vecA,total) firstprivate(sum)
{
#pragma omp for schedule(static)
    for (i = 0; i < NX; i++) {
        sum += vecA[i];
    }
#pragma omp critical(add)
{
total += sum;
}

}
    printf("Sum: %ld\n",total);



    return 0;
}
