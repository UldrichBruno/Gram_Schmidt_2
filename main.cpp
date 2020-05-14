#include <iostream>
#include "vector.h"
#include "matrix.h"
#include "engine.h"

using namespace std;

int main() {
    int inputDIM;

    string path1;   // Example: C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
    string path2;   // Example: C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt

    cout << "Welcome to program which find an Orthogonal base of given vectors from R^n." << endl;
    cout << "Input dimension of space:" << endl;
    cin >> inputDIM;
    cout
            << "Please, input path to your matrix of the dot product. Keep in mind, the matrix has to be symmetrical! Otherwise this program will work badly."
            << endl;
    cin >> path1;
    cout << "Please, enter path to find your vectors with n components. Otherwise this program will work badly."
         << endl;
    cin >> path2;
    struct matrix givenVectors = readGeneralMatrix(inputDIM, path2);
    struct matrix givenMatrix = readMatrix(inputDIM, path1);
    if (!checkMatrix(UTM(givenMatrix, true))) {
        cout << "Given matrix is not positive definite." << endl;
        exit(3);
    }
    cout << "Here is the given matrix:" << endl;
    printMatrix(givenMatrix);
    cout << "Here are the given vectors, which were linear independent:" <<endl;
    givenVectors = checkLN(UTM(givenVectors, false));
    for (int i = 0; i < givenVectors.sizeY; i++) {
        printVector(givenVectors.vector[i]);
    }
    cout << "This is your Orthogonal base:" << endl;

    struct matrix result = GramSchmidt(givenMatrix, givenVectors);

    for (int i = 0; i < result.sizeY; i++) {
        printVector(result.vector[i]);
    }
}