#include "Function.hpp"
#include <fstream>


namespace fr0dech
{
	void readmatrix(int matrix[100][100], int* n, int* m)
	{
		char symbol;
		std::ifstream in("input.txt", std::ios::in);

		while (!in.eof())
		{
			in >> *n >> *m;
			for (int i = 0; i < *n; i++) {
				for (int j = 0; j < *m; j++) {
					in >> matrix[i][j];
				}
			}
		}
	}

	void minmaxmatrix(int matrix[100][100], int* n, int* m)
	{
		int max = 1;
		int min = 99999999;
		for (int i = 0; i < *n; i++)
		{
			for (int j = 0; j < *m; j++)
			{
				if (matrix[i][j] < min)
					min = matrix[i][j];
				if (matrix[i][j] > max)
					max = matrix[i][j];
			}
		}
		int minsum = 0, maxsum = 0;
		while (min != 0)
		{
			minsum += min % 10;
			min /= 10;
		}
		while (max != 0)
		{
			maxsum += max % 10;
			max /= 10;
		}
		int matrixtemp[100];
		int sum = 0;
		for (int j = 0; j < *m; j++)
		{
			for (int i = 0; i < *n; i++)
			{
				sum += matrix[i][j];
			}
			matrixtemp[j] = sum;
			sum = 0;
		}

		if (abs(maxsum - minsum) <= 2)
		{
			int temp, tempm;
				for (int j = 0; j < *m; j++)
				{
					for (int k = 0; k < *m; k++)
					{
						if (matrixtemp[j] < matrixtemp[k])
						{
							for (int i = 0; i < *n; i++)
							{
									temp = matrixtemp[k];
									tempm = matrix[i][k];
									matrixtemp[k] = matrixtemp[j];
									matrix[i][k] = matrix[i][j];
									matrixtemp[j] = temp;
									matrix[i][j] = tempm;
							}
						}
					}
				}
		}
	}

	void writematrix(int matrix[100][100], int* n, int* m)
	{
		char symbol;
		std::ofstream outf("output.txt", std::ios::in);
		for (int i = 0; i < *n; i++)
		{
			for (int j = 0; j < *m; j++)
			{
				outf << matrix[i][j] << "\t";
			}
			outf << "\n";
		}
	}
}