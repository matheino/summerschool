/* Heat equation solver in 2D. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mpi.h>
#include "heat.h"

int main(int argc, char **argv)
{
    double a = 0.5;             //!< Diffusion constant
    field current, previous;    //!< Current and previous temperature fields

    double dt;                  //!< Time step
    int nsteps;                 //!< Number of time steps

    int image_interval = 100;    //!< Image output interval

    parallel_data parallelization; //!< Parallelization info

    int iter;                   //!< Iteration counter

    double dx2, dy2;            //!< delta x and y squared

    double start_clock;        //!< Time stamps

    /* TODO start: initialize MPI */
    int ntasks;
    int myid;
    int required = MPI_THREAD_FUNNELED;
    int provided;
    MPI_Init_thread(&argc,&argv,required,&provided);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&ntasks);

#pragma omp parallel private(iter)
{
    initialize(argc, argv, &current, &previous, &nsteps, &parallelization);

#pragma omp single
    {
    /* Output the initial field */
    write_field(&current, 0, &parallelization);

    /* Largest stable time step */
    dx2 = current.dx * current.dx;
    dy2 = current.dy * current.dy;
    dt = dx2 * dy2 / (2.0 * a * (dx2 + dy2));

    /* Get the start time stamp */
    start_clock = MPI_Wtime();
    } //single

    /* Time evolve */
    for (iter = 1; iter < nsteps; iter++) {
#pragma omp single
        exchange(&previous, &parallelization);
        evolve(&current, &previous, a, dt);
        if (iter % image_interval == 0) {
#pragma omp single
          write_field(&current, iter, &parallelization);
        }
        /* Swap current field so that it will be used
            as previous for next iteration step */
#pragma omp single
        swap_fields(&current, &previous);
    }
} // close #pragma omp

    /* Determine the CPU time used for the iteration */
    if (parallelization.rank == 0) {
      printf("Iteration took %.3f seconds.\n", (MPI_Wtime() - start_clock));
      printf("Reference value at 5,5: %f\n", previous.data[5][5]);
    }

    finalize(&current, &previous);
    /* TODO start: finalize MPI */
    MPI_Finalize();
    /* TODO end */

    return 0;
}
