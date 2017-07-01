#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
#pragma omp parallel
    {
      int N;
      int thread;
      N = omp_get_num_threads();
      thread = omp_get_thread_num();
      printf("thread nro: %d   ;nro of threads: %d\n",thread,N);
    }
    return 0;
}
