#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(int argc, char *argv[]) {
	
	int i,j,k,L,N,M,a;
	printf("Please type in row's quality of metrix\n");
	scanf("%d",&N);
	printf("Please type in column's quality of metrix\n");
	scanf("%d",&M);
	double A[M][N],x[N];
	#pragma omp parallel num_threads(4) private(i,j,a)
	for (i=1;i<=M;i++)
	{
		for (j=1;j<=N;j++)
		{
			k = omp_get_thread_num();
			a = time(NULL);
			printf("%d,%d\n",k,a);
			srand(a%(10*j+100*i)>>k);
			A[i][j]=rand();
			
		}
	}
	for (i=1;i<=M;i++)
	{
		for (j=1;j<=N;j++)
		{
			printf("%lf\n",A[i][j]);
			
		}
	}
	return 0;
}
