#include <iostream>
#include <vector>

using namespace std;


int busca(vector<int>& X, int inicio, int fin) {
    if (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (X[medio] == medio) {
            return medio; 
        }
        else if (X[medio] > medio) {
            return busca(X, inicio, medio - 1);
        }
        else {
            
            return busca(X, medio + 1, fin);
        }
    }

    return -1;
}

int main() {

    vector<int> X = { -10, -5, 0, 3, 7, 9, 12, 17 };

    int indiceEncontrado = busca(X, 0, X.size() - 1);

    if (indiceEncontrado != -1) {
        cout << "si se encontro X[i] = " << indiceEncontrado << endl;
    }
    else {
        cout << "no existe" << endl;
    }

    return 0;
}
