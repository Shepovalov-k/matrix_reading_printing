#include <stdio.h>
#include <stdlib.h>

int **matrix = NULL;

int M, N;

int read_size(int *M, int *N);
int read_matrix(int ***matrix, int M, int N);
int output(int **matrix, int M, int N);

int main()
{
	//printf("Enter the size of the matrix:\n");
	read_size(&M, &N);
	//printf("Enter the matrix:\n");
	read_matrix(&matrix, M, N);
	//printf("Your matrix:\n");
	output(matrix, M, N);
	return 0;
}

int read_size(int *M, int *N)
{
	return (scanf("%d %d", M, N) == 2);
}

int read_matrix(int ***matrix, int M, int N)
{
	*matrix = (int**)malloc(sizeof(int*) * M);
	for (int i = 0; i < M; i++)
		(*matrix)[i] = malloc(sizeof(int) * N);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			char ch = '\n';
			scanf("%d%c", &((*matrix)[i][j]), &ch);
		}
	return 1;
}

int output(int **matrix, int M, int N)
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			printf("%d", matrix[i][j]);
			if ((i + 1) < M)
			{
				if ((j + 1) < N)
				{
					printf(" ");
				}
				else if ((j + 1) == N)
				{
					printf("\n");
				}
			}
		}
	return 1;
};
