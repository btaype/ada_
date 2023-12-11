#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Elemento {
    int indice;
    int peso;
    double beneficio;
};


bool comparar(Elemento a, Elemento b) {
    double ratio_a = (double)a.beneficio / a.peso;
    double ratio_b = (double)b.beneficio / b.peso;
    return ratio_a > ratio_b;
}


double mochila(vector<Elemento>& elementos, int capacidad, vector<Elemento>& respuesta) {
    
    sort(elementos.begin(), elementos.end(), comparar);

    double valorTotal = 0.0;
    int pesoActual = 0;

    
    for (size_t y = 0;y<elementos.size();y++) {
        if (pesoActual + elementos[y].peso <= capacidad) {
            pesoActual += elementos[y].peso;
            valorTotal += elementos[y].beneficio;
            respuesta.push_back({ elementos[y].indice,elementos[y].peso,elementos[y].beneficio });
        }
        else {
            
            double fraccion = (double)(capacidad - pesoActual) / elementos[y].peso;
            double fin = fraccion * elementos[y].beneficio;
            valorTotal += fraccion * elementos[y].beneficio;
            respuesta.push_back({ elementos[y].indice,capacidad - pesoActual,fin });
            break;
        }
    }

    return  valorTotal;
}

int main() {

    vector<Elemento> elementos = { {1,10, 60}, {2,20, 100}, {3,30, 120} };
    int capacidadMochila = 50;
    vector<Elemento> respuesta;
    double valorOptimo = mochila(elementos, capacidadMochila,respuesta);
    cout << "beneficio total: " << valorOptimo << endl;

    for (size_t i = 0; i < respuesta.size(); i++) {
        cout << respuesta[i].indice << " " << respuesta[i].peso << " " << respuesta[i].beneficio << endl;
    }
    return 0;
}
