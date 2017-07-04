#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char *argv[])
{

  int my_id, omp_rank;
  int required = MPI_THREAD_FUNNELED;
  int provided;

  MPI_Init_thread(&argc,&argv,required,&provided);
  MPI_Comm_rank(MPI_COMM_WORLD,&my_id);

#pragma omp parallel private(omp_rank)
    { 
      omp_rank = omp_get_thread_num();
      printf("Hello World! From process: %d    thread: %d\n",my_id,omp_rank);
    }

 MPI_Finalize();
 return 0;
}
