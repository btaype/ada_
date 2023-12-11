#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void intercambiar(vector<int>& arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


int particion(vector<int>& arr, int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;

    for (int j = bajo; j < alto; ++j) {
        if (arr[j] <= pivote) {
            ++i;
            intercambiar(arr, i, j);
        }
    }

    intercambiar(arr, i + 1, alto);
    return i + 1;
}


int busca(vector<int>& arr, int bajo, int alto, int k) {
    if (bajo <= alto) {
        int indice_piv = particion(arr, bajo, alto);

        if (indice_piv == k) {
            return arr[indice_piv];
        }
        else if (indice_piv < k) {
            return busca(arr, indice_piv + 1, alto, k);
        }
        else {
            return busca(arr, bajo, indice_piv - 1, k);
        }
    }

    return -1; 
}


double mediana(vector<int>& arr) {
    int n = arr.size();

    if (n % 2 == 1) {
     
        return busca(arr, 0, n - 1, n / 2);
    }
    else {
   
        int mediana1 = busca(arr, 0, n - 1, n / 2 - 1);
        int mediana2 = busca(arr, 0, n - 1, n / 2);
        return (mediana1 + mediana2) / 2.0;
    }
}

int main() {
    vector<int> arr = { 12, 4, 5, 2, 7, 3, 19, 6 };

    double mediana1 = mediana(arr);

    cout << "La mediana es: " << mediana1 << endl;

    return 0;
}

