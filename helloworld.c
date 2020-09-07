#include <omp.h>
#include <stdio.h>
int main()
{
	#pragma omp parallel // It is OpenMP contruct which ask the number for no. threads from system( system decides the number thread to provide )
	
	{
		int ID=omp_get_thread_num(); 
		// it is a runtime routine which asks which thread it is
		printf("hello(%d)",ID);
		printf("world(%d)\n",ID);
	}
}
