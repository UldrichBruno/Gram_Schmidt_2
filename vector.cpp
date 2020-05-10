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
     cout << "--------------------------------------------------" << endl;
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

struct matrix readGeneralMatrix(int size, string path) {
    struct matrix a;
    a.size = size;
    a.sizeX = size;
    int x;
    ifstream inFile;
    inFile.open(path);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int i = 0;
    int j = 0;
    while (inFile >> x) {

        a.array[j][i] = x;
        a.vector[i].array[j] = x;
        if(j >= a.sizeX - 1){
            a.vector[i].size = a.sizeX;
            i++;
            j = 0;
        }
        else {
        j++;
        }
    }
    a.sizeY = i;
    inFile.close();

    return a;

}

struct matrix checkLN(struct matrix a){
   int b = 0;
    for(int i = 0; i < a.sizeY; i++){
        a.vector[i - b] = a.vector[i];
        if(a.array[i][i] == 0){
            b++;
        }

    }
    a.sizeY = a.sizeY - b;
    return a;
}