#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
  int size;
  int rank;
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);

  if (rank == 0){
  printf("Hello world!, rank =  %d,  totn = %d\n",rank,size);
  }
  else {
  printf("Hello world!, rank = %d\n", rank);
  }
  MPI_Finalize();
  return 0;
}
