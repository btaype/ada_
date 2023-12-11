#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int monedas_cambio(const vector<int>& nonedass, int cantidad) {
    vector<int> num_monedas(cantidad + 1, INT_MAX);
    vector<int> seleccion(cantidad + 1, -1);

    num_monedas[0] = 0;

    for (int monto = 1; monto <= cantidad; ++monto) {
        for (int tipo_moneda = 0; tipo_moneda < nonedass.size(); ++tipo_moneda) {
            if (nonedass[tipo_moneda] <= monto) {
                int subproblema = num_monedas[monto - nonedass[tipo_moneda]];
                if (subproblema != INT_MAX && subproblema + 1 < num_monedas[monto]) {
                    num_monedas[monto] = subproblema + 1;
                    seleccion[monto] = tipo_moneda; 
            }
        }
    }

    if (num_monedas[cantidad] == INT_MAX) {
        return -1;  
    }
    else {
        cout << "monedas que se utilizan: ";
        int monto_restante = cantidad;
        while (monto_restante > 0) {
            int tipo_moneda_index = seleccion[monto_restante];
            cout << nonedass[tipo_moneda_index] << " ";
            monto_restante -= nonedass[tipo_moneda_index];
        }
        cout << endl;
        return num_monedas[cantidad];
    }
}

int main() {
   
    vector<int> nonedass = { 100, 90, 1 };
    int cantidad = 180;

    int resultado = monedas_cambio(nonedass, cantidad);

    if (resultado != -1) {
        cout << "minimo mondeas: " << resultado << endl;
    }
    else {
        cout << "no es posible" << endl;
    }

    return 0;
}
