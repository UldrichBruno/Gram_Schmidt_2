#ifndef vectorH
#define vectorH

#define MAX_SIZE_OF_VECTOR 50

struct vector{
    double array[MAX_SIZE_OF_VECTOR];
    int size;
};

void printVector(struct inputVector );
struct vector readVector(int size, std::string path);



#endif
