#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int mochila(int capacidad, const vector<int>& pesos, const vector<int>& valores, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (pesos[i - 1] <= w) {
                dp[i][w] = max(valores[i - 1] + dp[i - 1][w - pesos[i - 1]], dp[i - 1][w]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidad];
}

int main() {
    
    vector<int> pesos = { 1,2, 5, 6, 7 };
    vector<int> valores = { 1,6,18, 22, 28 };
    int capacidad = 11;
    int n = pesos.size();

    int resultado = mochila(capacidad, pesos, valores, n);

    cout << "ebenfiocio maximo: " << resultado << endl;

    return 0;
}
