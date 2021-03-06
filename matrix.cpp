//
// Created by Uzivatel on 10.05.2020.
//
#include "matrix.h"
#include "vector.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct matrix readMatrix(int size, string path1) {
    struct matrix a;
    a.size = size;
    a.sizeY = size;
    a.sizeX = size;
    int x;
    ifstream inFile;
    inFile.open(path1);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(4); // terminate with error
    }
    while (inFile >> x) {
        for (int i = 0; i < a.size; i++) {
            for (int j = 0; j < a.size; j++) {
                a.array[i][j] = x;
                inFile >> x;
            }
        }
    }
    inFile.close();

    return a;

}

void printMatrix(struct matrix a) {
    for (int i = 0; i < a.sizeX; i++) {
        for (int j = 0; j < a.sizeY; j++) {
            cout << setw(7) << setprecision(3) << a.array[i][j] << " ";
        }
        cout << endl;
    }
    cout <<"--------------------------------------------------"<< endl;

}

bool check(struct matrix a, int line, int col) {    //Catches zeroes to lead the function UTM to success.
    return a.array[line][col] != 0;
}

bool checkSingular(int numOfSteps, int inputDIM){
    return numOfSteps < inputDIM + 10;
}

struct matrix zeroingElement(struct matrix a, int lineNullHead, int lineReadHead, double coef) {    // Makes zeroes under the main diagonal.
    for (int i = 0; i < a.sizeY; i++) {
        a.array[lineNullHead][i] = a.array[lineNullHead][i] + a.array[lineReadHead][i] * coef;
    }
    return a;
}

double findCoef(struct matrix a, int lineNullHead, int lineReadHead) {  // Finds a coefficient, which multiplies a number on the main diagonal to annul numbers below.
    double coef;
    return coef = (-1 * (a.array[lineNullHead][lineReadHead] / a.array[lineReadHead][lineReadHead]));
}

struct matrix moveLine(struct matrix a, int lineReadHead) {
    double opmatrix[MAX_SIZE_OF_MATRIX];
    for (int k = 0; k < a.sizeY; k++) {
        opmatrix[k] = a.array[lineReadHead][k];
    }

    for (int i = lineReadHead; i < a.sizeX; i++) {
        for (int k = 0; k < a.sizeY; k++) {
            a.array[i][k] = a.array[i + 1][k];
        }
    }

    for (int k = 0; k < a.sizeY; k++) {
        a.array[a.sizeX - 1][k] = opmatrix[k];
    }
    return a;

}

struct matrix UTM(struct matrix a, bool interuptOn) {   // Upper-triangular-matrix function.
    int numOfLoops = 0;
    Start:
    for (int i = 0; i < a.sizeY; i++) {         // ReadHead
        if (check(a, i, i) == 1) {
            for (int j = i + 1; j < a.sizeX; j++) {    //NullHead.
                double coef = findCoef(a, j, i);
                a = zeroingElement(a, j, i, coef);
            }
        } else {
            numOfLoops++;
            if (checkSingular(numOfLoops, a.sizeX) == 1) {
                a = moveLine(a, i);
                goto Start;
            } else{
                if(interuptOn){
                    cout << "Given matrix is singular!" << endl;
                    exit(5);
                } else{
                    return a;
                }
            }
        }
    }
    return a;
}

bool checkMatrix(struct matrix UTMMatrix){
    double subdet ;
    for(int j = 0; j < UTMMatrix.size; j++){
        for (int i = 0; i < j; i++){
            subdet = subdet * UTMMatrix.array[i][i];
            if(subdet<0){
                return false;
            }
        }
        return true;
    }
}
