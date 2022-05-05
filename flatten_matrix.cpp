#include <iostream>

void print_matrix(int ***, int, int, int);
int index1D(int, int, int, int, int);
int main()
{
    int n, m, p;
    std::cout << "please enter 3D matrix dimentions: \n";
    std::cout << "length: ";
    std::cin >> n;
    std::cout << "width: ";
    std::cin >> m;
    std::cout << "height: ";
    std::cin >> p;


    // create a dynamic 3d matrix
    int ***mat3D = new int **[n];
    for (int i = 0; i < n; i++)
        mat3D[i] = new int *[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat3D[i][j] = new int[p];
        }
    }

    //create a 1D array to store the matrix
    int* flat_matrix = new int[n * m * p];

    // intput the 3D matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                std::cin >> mat3D[i][j][k];
                flat_matrix[index1D(i, j, k, n, m)] = mat3D[i][j][k];
            }
        }
    }
    
}

void print_matrix(int ***mat3D, int n, int m, int p)
{
    std::cout << "the matrix is: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                std::cout << mat3D[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
int index1D(int i, int j, int k, int n, int m)
{
    return i + n*(j + m*k);
}
