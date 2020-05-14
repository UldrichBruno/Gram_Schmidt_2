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

            double matrixPointVectorRight = givenMatrix.array[i][j] * (whichOneRight.array[j]);
            partialSum = matrixPointVectorRight + partialSum;
        }
        double c = (whichOneLeft.array[i]) * partialSum;
        product = product + c;
    }
    return product;
}

struct matrix GramSchmidt(struct matrix givenMatrix, struct matrix vectorMatrix){
    struct matrix Result;
    Result.sizeY = vectorMatrix.sizeY;
    Result.sizeX = vectorMatrix.sizeX;
    Result.size = vectorMatrix.size;
    Result.vector[0] = vectorMatrix.vector[0];
    for (int i = 1; i < vectorMatrix.sizeY; i++){
        struct vector sum;
        sum.size = vectorMatrix.size;
        for (int k = 0; k < sum.size ; ++k) {
            sum.array[k] = 0;
        }
        for (int j = 0 ; j < i ; j++){
            double partial = dotProduct(givenMatrix, vectorMatrix.vector[i], Result.vector[j]) / dotProduct(givenMatrix, Result.vector[j], Result.vector[j]);
            struct vector partialSum = scalaeMultiplVector(Result.vector[j], partial);
            sum = vectorAddVector(partialSum, sum);
        }
        sum = scalaeMultiplVector(sum, -1);
        Result.vector[i] = vectorAddVector(sum, vectorMatrix.vector[i]);

    }
    return Result;
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