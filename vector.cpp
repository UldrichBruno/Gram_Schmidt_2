
#include "vector.h"
#include "matrix.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void printVector(struct vector v) {
    for (int i = 0; i < v.size; i++) {
            cout << setw(7) << setprecision(3) << v.array[i]<< " ";
        }
        cout << endl;
    cout <<"--------------------------------------------------"<< endl;
}

struct vector readVector(int size, string path) {
    struct vector v;
    v.size = size;
    int x;
    ifstream inFile;
    inFile.open(path);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >> x) {
        for (int i = 0; i < v.size; i++) {
                v.array[i] = x;
                inFile >> x;
            }
    }
    inFile.close();
    return v;
}

struct matrix addVectorToMatrix(struct matrix m, struct vector v) {
    m.sizeX++;
    m.sizeY = v.size;
    for (int i = 0; i < v.size; i++) {
        m.array[sizeX][i] = v.array[i];
    }
}

struct matrix readGeneralMatrix(int size, string path) {
    struct matrix a;
    a.size = size;
    a.sizeY = size;
    int x;
    ifstream inFile;
    inFile.open(path1);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int i = 0;
    while (inFile >> x) {
        i++;
        for (int j = 0; j < a.sizeY; j++) {
            a.array[i][j] = x;
            inFile >> x;
        }
    }
    inFile.close();

    return a;

}
