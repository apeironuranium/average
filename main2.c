#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */




double mean(double* mean_array){
	double mean = 0;
	int aSize = 5;
	
    #pragma omp parallel num_threads(4)
	{
  		#pragma omp for reduction(+:mean)
  		for (int i=0; i<aSize; i++) {
     		mean = mean + mean_array[i];
  		}
  		printf("hello %d\n", omp_get_thread_num());
	}
	printf("%f\n", mean);
	mean = mean / aSize;
	return mean;
}


int main(){
	double myArray[5] = {6.0, 1.0, 2.0, 3.0, 4.0};
	for (int i = 0; i < 5; i++){
		printf("%f ", myArray[i]);
	}
	printf("\n");
	double res = mean(myArray);
	printf("%f", res);
	return 1;
}
