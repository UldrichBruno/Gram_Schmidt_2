#ifndef vectorH
#define vectorH
#include <string>

#define MAX_SIZE_OF_VECTOR 50

struct vector{
    double array[MAX_SIZE_OF_VECTOR];
    int size;
};





void printVector(struct vector inputVector);
struct vector readVector(int size, std::string path);
struct matrix addVectorToMatrix(struct matrix m, struct vector v);
struct matrix readGeneralMatrix(int size, std::string path);
struct matrix checkLN(struct matrix a);



#endif
