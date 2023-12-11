#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct progrma {
    int id;
    int tamano;


};


bool acen_decen(const progrma& a, const progrma& b) {
    return a.tamano < b.tamano;
}


void maximizar(int capacidadDisco, vector<progrma>& progra) {


    sort(progra.begin(), progra.end(),acen_decen);
    int ocuapdo = 0;
    int n_programas = 0;

    for (size_t i = 0;i<progra.size();i++) {
        if (ocuapdo + progra[i].tamano <= capacidadDisco) {
            ocuapdo += progra[i].tamano;
            n_programas++;
            cout << "indice: " << progra[i].id << " almacenado: " << progra[i].tamano << " MB." << endl;
        }
    }

    cout << "losprogramas alamacenados: " << n_programas << endl;
}

int main() {
    int capacidadDisco = 30; 
    int n = 5;
    vector<progrma> progra;
  

    vector<int> tamanos = { 10, 5, 8, 12, 7 };

    for (int i = 1; i <= n; i++) {
        progra.push_back({i,tamanos[i-1]});
    }

    
    maximizar(capacidadDisco, progra);

    return 0;
}
