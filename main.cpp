#include <iostream>
#include "vector.h"
#include "matrix.h"
#include "engine.h"

using namespace std;

int main() {
        int numOfVectors;
        int inputDIM;

        string path1 = "C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt";        // Example: C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
        string path2 = "C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt";        // Example: C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt

        cout << "Welcome to program which find an Orthogonal base of given vectors from C^n." << endl;
        cout << "Please, enter your vectors with n složky (max n samples). Otherwise this program will work badly." << endl;
        cout << "Input dimension of space:" << endl;
        cin >> inputDIM;
    struct matrix givenVectors = readGeneralMatrix(inputDIM, path2);
    struct matrix givenMatrix = readMatrix(inputDIM, path1);
    if(!checkMatrix(UTM(givenMatrix, true))){
        cout << "Given matrix is not positive definite." << endl;
        exit(3);
    }
     givenVectors = checkLN(UTM(givenVectors, false));
    for(int i = 0; i < givenVectors.sizeY; i++){
        printVector(givenVectors.vector[i]);
    }

    struct vector result[MAX_SIZE_OF_MATRIX];
    result[0] = givenVectors.vector[0];
    for(int i =1; i < givenVectors.sizeY; i++){
        result[i] = Gram_Schmidt(givenMatrix, givenVectors.vector[i], givenVectors.vector[i-1], i);
    }
    for(int i = 0; i < givenVectors.sizeY; i++){
        printVector(result[i]);
    }

      //  cout << "" << endl;
     //   cout << "Your matrix: " << endl;


   //     printMatrix(givenMatrix);
    //    printMatrix(UTM(givenMatrix));




     //   cout << checkMatrix(UTM(givenMatrix));
}