#include <stdio.h>
#include <omp.h>
static long num_steps = 1000000;
double step;

#define NUM_THREADS 4

int main ()
{
    int i;
    double pi = 0.0, x, sum = 0.0;
    double start_time, run_time;

    step = 1.0/(double) num_steps;

    start_time = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel firstprivate(sum) private(x,i) //cada thread tera uma cópia local com o valor = 0
    {
        int id, n_threads, n_threads_global;
        
        id = omp_get_thread_num();
        n_threads = omp_get_num_threads();

        if(id == 0)
            n_threads_global = n_threads;
        
        for(i=id, sum=0.0; i< num_steps; i=i+n_threads)
        {
            x = (i+0.5)*step;
            sum += 4.0/(1.0+x*x);
        }

        #pragma omp critical
            pi += sum * step;
    }

    run_time = omp_get_wtime() - start_time;
    printf("%ld;%f;%f\n", num_steps, pi, run_time);
}