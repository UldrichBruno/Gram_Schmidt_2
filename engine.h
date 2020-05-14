//
// Created by Uzivatel on 10.05.2020.
//

#ifndef GRAM_SCHMIDT_ENGINE_H
#define GRAM_SCHMIDT_ENGINE_H

double dotProduct(struct matrix Matrix, struct vector  whichOneLeft, struct vector whichOneRight);
struct matrix GramSchmidt(struct matrix givenMatrix, struct matrix vectorMatrix);
double sum(struct matrix Matrix, struct vector whichOneGet, struct vector theOneBefore);

#endif //GRAM_SCHMIDT_ENGINE_H
