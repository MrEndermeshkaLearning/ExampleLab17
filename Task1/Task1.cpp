#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10
#define M 10
void printArr(int arr[N][M])
{
	for(int i=0; i<N; i++)
	{
		for(int j=0;j<M;j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}
void ReverseSortByChoose(int arr[], int n) {
	int minPosition, temp;
	for (int i = 0; i < n; i++)
	{
		minPosition = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[minPosition] > arr[j]) {
				minPosition = j;
			}
		}
		temp = arr[minPosition];
		arr[minPosition] = arr[i];
		arr[i] = temp;
	}
	int tmp[N];
	for(int j=N-1, i=0; j>-1; i++,j--)
	{
		tmp[j] = arr[i];
	}
	for (int j = 0; j <N; j++)
	{
		arr[j] = tmp[j];
	}
}

int main()
{
	//два примера вариант 10, вариант 15
	int arr[N][M];
	srand(time(nullptr));
	for(int i=0;i<N;i++)
	{
		for(int j=0; j<M; j++)
		{
			arr[i][j] = rand() % (-N - M) + -N;
		}
	}
	printArr(arr);
	int tempArray[N];
	for(int i=0, j=0 ; i<N; i++, j++)
	{
		tempArray[i] = arr[i][j];
	}
	ReverseSortByChoose(tempArray, N);
	for (int i = 0, j = 0; i < N; i++, j++)
	{
		arr[i][j] = tempArray[i];
	}
	printf("Result array=>\n");
	printArr(arr);
	printf("press any key to look at variant 15\n");
	system("pause");

//////////var 15
	int numofNEEDROW;
	printf("StartArray\n");
	printArr(arr);
	while (true)
	{
		printf("get me num < %d\n", M);
		scanf_s("%d", &numofNEEDROW);
		if(numofNEEDROW<M)
		{
			break;
		}
	}
	int tempArr[M];
	for(int i=0; i<N; i++)
	{
		tempArray[i]=arr[i][numofNEEDROW];
	}
	ReverseSortByChoose(tempArray, M);
	for (int i = 0; i < N; i++)
	{
		arr[i][numofNEEDROW]= tempArray[i];
	}
	printf("resultArray=>\n");
	printArr(arr);
}