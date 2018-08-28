// THIS IS A SPMD DESIGN PATTERN IMPLEMENTED FOR PI PROGRAM - BUT WITH FALSE SHARING

#include <stdio.h>
#include <omp.h>
static long num_steps = 1000000;
double step;
int e;

#define NUM_THREADS 4

int main ()
{
    int i, n_threads_global;
    double x, pi, sum[NUM_THREADS];
    double start_time, run_time;

    step = 1.0/(double) num_steps;

    start_time = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        int i, id, n_threads;
        double x;
        
        id = omp_get_thread_num();
        n_threads = omp_get_num_threads();

        if(id == 0)
            n_threads_global = n_threads;
         
        for(i=id, sum[id]=0.0; i< num_steps; i=i+n_threads)
        {
            x = (i-0.5)*step;
            sum[id] += 4.0/(1.0+x*x);
        }
    }
    
    for(i=0, pi=0.0; i<n_threads_global; i++)
        pi += sum[i] * step;

    run_time = omp_get_wtime() - start_time;
    printf("%ld;%f;%f\n", num_steps, pi, run_time);
}