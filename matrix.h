#ifndef matrixH
#define matrixH




#define MAX_SIZE_OF_MATRIX 50

struct matrix{
    double array[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    int size;

};

struct matrix readMatrix(int inputDIM, std::string path);       // Load matrix from a file.
void printMatrix(struct matrix a);
double determinant(struct matrix a);
bool checkMatrix(struct matrix givenMatrix);
std::struct matrix UTM(struct matrix a);                         // Reduce the matrix to an upper triangular matrix.
double determinant(struct matrix a);
double cofactor(struct matrix a, int y, int x);

#endif
