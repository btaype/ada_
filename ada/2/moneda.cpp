clude <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Moneda {
    int valor;
    int cantidad;
};


bool compararMonedas(Moneda a, Moneda b) {
    return a.valor > b.valor;
}


void darCambio(vector<Moneda>& monedas, int cambio) {

    sort(monedas.begin(), monedas.end(), compararMonedas);

    for (const Moneda& moneda : monedas) {
        int n_monedas = min(cambio / moneda.valor, moneda.cantidad);
        if (n_monedas > 0) {
            cout << "cantidad: " << n_monedas << "   valor de la moneda: " << moneda.valor << "$" << endl;
            cambio -= n_monedas * moneda.valor;
        }
    }

    if (cambio > 0) {
        cout << "No se puede dar cambio exacto." << endl;
    }
}

int main() {

    vector<Moneda> monedas = { {25, 3}, {10, 2}, {5, 5}, {1, 10} };
    int cantidadTotal = 63;

    darCambio(monedas, cantidadTotal);

    return 0;
}
