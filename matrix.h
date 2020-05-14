#ifndef matrixH
#define matrixH


#include "vector.h"

#define MAX_SIZE_OF_MATRIX 50

struct matrix{
    double array[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    int size;
    int sizeX = 0;
    int sizeY = 0;
    struct vector vector[MAX_SIZE_OF_MATRIX];

};

struct matrix readMatrix(int inputDIM, std::string path);   // Load matrix from a file.
void printMatrix(struct matrix a);
double determinant(struct matrix a);
struct matrix UTM(matrix a, bool b);    // Reduce the matrix to an upper triangular matrix.
bool checkMatrix(struct matrix UTMMatrix);
double subdeterminant(struct matrix UTMMatrix);
double cofactor(struct matrix a, int y, int x);
double dotProduct(struct vectors v, struct matrix givenMatrix, double whichOneLeft, double whichOneRight);

#endif
