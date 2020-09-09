#include <omp.h>
#include <stdio.h>
static long num_steps = 100000; double step;

void main ()
{ 
	int i, nthreads; double pi, sum[8];
	step = 1.0/(double) num_steps;
	omp_set_num_threads(8);
	
	#pragma omp parallel
	{
		int i;
		double x;
		int id = omp_get_thread_num();
		int nthrds = omp_get_num_threads();

		for (i=id, sum[id]=0.0;i< num_steps; i=i+nthrds) {
			x = (i+0.5)*step;
			sum[id] += 4.0/(1.0+x*x);
		}
	}
	
	for(i=0, pi=0.0;i<8;i++)pi += sum[i];
	pi *= step;
	printf("pi=%f\n",pi); 
}
