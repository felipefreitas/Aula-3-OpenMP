//PI PROGRAM using reduction from OpenMP avoiding true data dependence

#include <stdio.h>
#include <omp.h>
static long num_steps = 1000000;
double step;
int e;
int main ()
{
    int i;
    double pi, sum = 0.0;
    double start_time, run_time;

    step = 1.0/(double) num_steps;
    start_time = omp_get_wtime();

    #pragma omp parallel
    {
        double x;

        #pragma omp for private(x) reduction(+:sum)
            for (i=1;i<= num_steps; i++){
                x = (i-0.5)*step;
                sum = sum + 4.0/(1.0+x*x);
            }
    }

    pi = step * sum;
    run_time = omp_get_wtime() - start_time;
    printf("%ld;%f;%f\n", num_steps, pi, run_time);
}