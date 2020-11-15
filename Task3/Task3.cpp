#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10
#define M 10
//прототипы функций, дают программе знать какие функции будут написаны в итоге
void printArr(double arr[][M]);
void insertSort(double arr[], int n);
void selectSort(double arr[], int n);
void FromDoubleToSingleArray(double arr[][M]);
// так надо делать когда хочешь написать функцию под мейном.
int main()
{
	srand(time(nullptr));
	double arr[N][M];
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			arr[i][j] = rand() % (-N*100 - M*100) + -N*100;
			arr[i][j] /= (double)100;
		}
	}
	printArr(arr);
	FromDoubleToSingleArray(arr);
}

void FromDoubleToSingleArray(double arr[][M])
{
	double arrTemp[N * M];
	int temp = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			arrTemp[temp] = arr[i][j];
			temp++;
		}
	}
	while (true)
	{
		printf("1. Insert or 2. Select(buble) sort\n");
		scanf_s("%d", &temp);
		if(temp>0&&temp<3)
		{
			break;
		}
	}
	switch (temp)
	{
	case 1:
		{
		insertSort(arrTemp, N * M);
		}
		break;
	case 2:
		{
		selectSort(arrTemp, N * M);
		}
		break;
	}
	temp = 0;
	for(int i=0; i<N;i++)
	{
		for(int j=0; j<M;j++)
		{
			arr[i][j] = arrTemp[temp];
			temp++;
		}
	}
	printArr(arr);
}

void printArr(double arr[N][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%8.2lf", arr[i][j]);
		}
		printf("\n");
	}
}
void selectSort(double arr[], int size)
{
	double tmp;
	int i, j, pos;
	for (i = 0; i < size; ++i) // i - номер текущего шага
	{
		pos = i;
		tmp = arr[i];
		for (j = i + 1; j < size; ++j) // цикл выбора наименьшего элемента
		{
			if (arr[j] < tmp)
			{
				pos = j;
				tmp = arr[j];
			}
		}
		arr[pos] = arr[i];
		arr[i] = tmp; // меняем местами наименьший с a[i]
	}
}
void insertSort(double arr[], int n) {
	for (int i = 1; i < n; i++) {
		int k = i;
		while (k > 0 && arr[k - 1] > arr[k])
		{
			double temp = arr[k - 1];
			arr[k - 1] = arr[k];
			arr[k] = temp;
			k -= 1;
		}
	}
}