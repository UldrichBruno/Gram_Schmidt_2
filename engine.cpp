//
// Created by Uzivatel on 10.05.2020.
//

#include "engine.h"
#include "matrix.h"
#include "vector.h"

double dotProduct(struct matrix givenMatrix, struct vector whichOneLeft, struct vector whichOneRight){
    double product = 0;
    for (int i = 0; i < givenMatrix.size; i++){
        double partialSum = 0;
        for (int j = 0; j < givenMatrix.size; j++) {
            double matrixPointVectorRight = givenMatrix.array[i][j] * (whichOneRight.array[j] + j);
            partialSum = matrixPointVectorRight + partialSum;
        }
        double c = (whichOneLeft.array[i] + i) * partialSum;
        product = product + c;
    }
    return product;

}

double sum(struct matrix givenMatrix, struct vector insteadOf, struct vector theOneBefore, int whichOne){
    double dotProd = 0;
    double norm = 0;
    double partial = 0;
    dotProd = dotProduct(givenMatrix, insteadOf, theOneBefore);
    norm = dotProduct(givenMatrix, theOneBefore, theOneBefore);
    for (int i = 0; i < whichOne - 1; i++){
        double e = (dotProd * theOneBefore.array[i])/(norm * norm);
        partial = partial + e;
    }
    return partial;

}

struct vector Gram_Schmidt(struct matrix givenMatrix, struct vector insteadOf, struct vector theOneBefore, int whichOne){
    struct vector whichOneGet;
    for (int i = 1; i < whichOne; i++) {
        whichOneGet.array[i] = insteadOf.array[i] - sum(givenMatrix, insteadOf, theOneBefore);
    }
    return whichOneGet;

}