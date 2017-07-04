#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <omp.h>
int main(int argc, char *argv[]){

  int rank_id;
  int *thread_id_addr;
  int thread_id;
  int ntasks;
  int required = MPI_THREAD_MULTIPLE;
  int provided;
  int *thread0_id;
  
  MPI_Init_thread(&argc,&argv,required,&provided);
  MPI_Comm_size(MPI_COMM_WORLD,&ntasks);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank_id);
  
#pragma omp parallel private(thread_id)
{ 
  thread0_id =  malloc(sizeof(int));
  thread_id_addr = malloc(sizeof(int));
  thread_id = omp_get_thread_num();
  thread_id_addr[1] = thread_id;

  if (rank_id == 0){
    for(int i = 1; i < ntasks; i++){
      MPI_Send(thread_id_addr,1,MPI_INT,i,thread_id,MPI_COMM_WORLD);
    }
  }
  else{
      MPI_Recv(&thread0_id,1,MPI_INT,0,thread_id,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
  }
  printf("I am thread %d in rank %d corresponding to thread %d in rank 0\n",thread_id,rank_id,thread0_id);
  }


  MPI_Finalize();

}
