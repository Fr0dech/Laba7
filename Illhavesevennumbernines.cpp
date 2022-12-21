#include <iostream>
#include "function.hpp"

int main()
{
    int matrix[100][100];
    int n, m;
    fr0dech::readmatrix(matrix, &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << '\t';
        std::cout << '\n';
    }
    std::cout << std::endl;
    fr0dech::minmaxmatrix(matrix, &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << '\t';
        std::cout << '\n';
    }
    fr0dech::writematrix(matrix, &n, &m);
}

