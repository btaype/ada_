#include <iostream>
#include <vector>

using namespace std;

vector<int> quicksort(vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int pivote = arr.back();
    vector<int> menores;
    vector<int> mayores;

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] <= pivote) {
            menores.push_back(arr[i]);
        }
        else {
            mayores.push_back(arr[i]);
        }
    }

    menores = quicksort(menores);
    mayores = quicksort(mayores);

    
    vector<int> resultado;
   
    resultado.insert(resultado.begin(), menores.begin(), menores.end());
    resultado.push_back(pivote);
    resultado.insert(resultado.end(), mayores.begin(), mayores.end());

    return resultado;
}

int main() {
    vector<int> arreglo = { 7, 4, 3, 9, 23, 3, 6 };
    vector<int> resultado = quicksort(arreglo);


    for (const auto& elemento : resultado) {
        cout << elemento << " ";
    }

    return 0;
}
