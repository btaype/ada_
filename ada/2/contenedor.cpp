#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct contenedores {
    int indice;
    int peso;
    contenedores(int a, int b) {
        indice = a;
        peso = b;
    }
};

bool comparar(contenedores a, contenedores b) { return a.peso < b.peso; }

void voraz(const vector<contenedores>& contenedores_orig, vector<contenedores>& contenedores_resultado, int k) {
    vector<contenedores> contenedores = contenedores_orig;  

    sort(contenedores.begin(), contenedores.end(), comparar);
    int peso_total = 0;

    for (size_t i = 0; i < contenedores.size(); i++) {
        if (peso_total + contenedores[i].peso <= k) {
            contenedores_resultado.push_back(contenedores[i]);
            peso_total += contenedores[i].peso;
        }
    }
}

int main() {
    vector<contenedores> contenedores_orig = {
        contenedores(1, 4),
        contenedores(2, 2),
        contenedores(3, 1),
        contenedores(4, 10),
        contenedores(5, 12),
        contenedores(6, 6),
        contenedores(9, 3),
    };

    int peso_max = 10;
    vector<contenedores> contenedores_resultado;

    voraz(contenedores_orig, contenedores_resultado,peso_max);

    int suma = 0;
    for (size_t i = 0; i < contenedores_resultado.size(); i++) {
        suma += contenedores_resultado[i].peso;
        cout << "contenedores " << contenedores_resultado[i].indice << " peso: " << contenedores_resultado[i].peso << endl;
    }
    cout << "total" << suma;

    return 0;
}
