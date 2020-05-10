//
// Created by Uzivatel on 10.05.2020.
//

#ifndef GRAM_SCHMIDT_ENGINE_H
#define GRAM_SCHMIDT_ENGINE_H

double dotProduct(struct matrix Matrix, struct vector  whichOneLeft, struct vector whichOneRight);
double sum(struct matrix Matrix, struct vector whichOneGet, struct vector theOneBefore);
double dotProduct(struct matrix Matrix, struct vector whichOneLeft, struct vector whichOneRight);
struct vector Gram_Schmidt(struct matrix givenMatrix, struct vector insteadOf, struct vector theOneBefore, int whichOne);


#endif //GRAM_SCHMIDT_ENGINE_H
