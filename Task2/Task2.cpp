#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 10

int main()
{
	int arr[N][M];
	srand(time(nullptr));
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			arr[i][j] = rand() % (-N - M) + -N;
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	int tempArr[N][M - 1];
	int tempMin = INT_MAX;
	int numCol;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] < tempMin)
			{
				tempMin = arr[i][j];
				numCol = j;
			}
		}
	}
	int k = 0;
	printf("Column # = %d\n", numCol);
	printf("resulArray=>\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j != numCol)
			{
				tempArr[i][k] = arr[i][j];
				k++;
			}
			else
			{
				continue;
			}
		
		}
		k = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M-1; j++)
		{
			printf("%4d", tempArr[i][j]);
		}
		printf("\n");
	}
	
}