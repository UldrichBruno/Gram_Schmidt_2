#ifndef matrixH
#define matrixH



#define MAX_SIZE_OF_MATRIX 50

struct matrix{
    double array[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    int size;
    int sizeX;
    int sizeY;

};

struct matrix readMatrix(int inputDIM, std::string path);       // Load matrix from a file.
void printMatrix(struct matrix a);
double determinant(struct matrix a);
struct matrix UTM(struct matrix a);                         // Reduce the matrix to an upper triangular matrix.
bool checkMatrix(struct matrix a);
double subdeterminant(struct matrix a);
double cofactor(struct matrix a, int y, int x);
#endif
