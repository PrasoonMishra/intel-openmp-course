#include <omp.h>
#include <stdio.h>
static long num_steps = 100000; double step;

void main ()
{ 
	int i, nthreads; double pi;
	step = 1.0/(double) num_steps;
	omp_set_num_threads(8);
	
	#pragma omp parallel
	{
		int i;
		double x,sum;
		int id = omp_get_thread_num();
		int nthrds = omp_get_num_threads();

		if(id == 0) nthreads = omp_get_num_threads();

		for (i=id, sum=0.0;i< num_steps; i=i+nthrds) {
			x = (i+0.5)*step;
			sum += 4.0/(1.0+x*x);
		}
		#pragma omp critical
		pi += sum*step; 
	}
	printf("pi=%f\n",pi); 
}
