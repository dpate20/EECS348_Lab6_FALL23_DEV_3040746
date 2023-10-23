#include <iostream>
#include <fstream>
using namespace std;

const int size_constraint = 100;
void readfilematrix(int matrix1[][size_constraint], int matrix2[][size_constraint], int &size);
void printmatrix(int matrix[][size_constraint], int size);
void addingmatrix(int matrix1[][size_constraint], int matrix2[][size_constraint], int addedmatrix[][size_constraint], int size);
void multiplymatrix(int matrix1[][size_constraint], int matrix2[][size_constraint], int multipliedmatrix[][size_constraint], int size);
void subtractingmatrix(int matrix1[][size_constraint], int matrix2[][size_constraint], int subtractedmatrix[][size_constraint], int size);


void readfilematrix(int matrix1[][size_constraint], int matrix2[][size_constraint], int &size)
{
    ifstream file("matrix_input.txt");
    file >> size;

  for (int i = 0; i < size; i++)
  {
      for (int j = 0; j < size; j++) 
      {
          file >> matrix1[i][j];
      }
  }

  for (int i = 0; i < size; i++)
  {
      for (int j = 0; j < size; j++) 
      {
          file >> matrix2[i][j];
      }
  }
    file.close();
}

void printmatrix(int matrix[][size_constraint], int size)
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addingmatrix(int matrix1[][size_constraint], int matrix2[][size_constraint], int addedmatrix[][size_constraint], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            addedmatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplymatrix(int matrix1[][size_constraint], int matrix2[][size_constraint], int multipliedmatrix[][size_constraint], int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            multipliedmatrix[i][j] = 0;
            for (int k = 0; k < size; k++) 
            {
                multipliedmatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

}

void subtractingmatrix(int matrix1[][size_constraint], int matrix2[][size_constraint], int subtractedmatrix[][size_constraint], int size)
{
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                subtractedmatrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
}

int main()
{
    int size; int matrixA[size_constraint][size_constraint]; int matrixB[size_constraint][size_constraint]; int addmatrix[size_constraint][size_constraint]; int multimatrix[size_constraint][size_constraint]; int subtmatrix[size_constraint][size_constraint];
    readfilematrix(matrixA, matrixB, size);
    addingmatrix(matrixA, matrixB, addmatrix, size);
    multiplymatrix(matrixA, matrixB, multimatrix, size);
    subtractingmatrix(matrixA, matrixB, subtmatrix, size);

    cout << "--Devarth Patel--" << endl;

    cout << "==Lab#6: IDE, Compiled Programs (C++ Programming)==" << endl;

    cout << "Matrix A: " << endl;
    printmatrix(matrixA,size);

    cout << "Matrix B: " << endl;
    printmatrix(matrixB,size);

    cout << "Matrix Sum (A+B): " << endl;
    printmatrix(addmatrix,size);

    cout << "Matrix Product (A*B): " << endl;
    printmatrix(multimatrix, size);

    cout << "Matrix Difference (A-B): " << endl;
    printmatrix(subtmatrix, size);

    return 0;

}

