#include <iostream>
#include <vector>

using namespace std;


int kaesimo(vector<int>a, int k) {
    if (a.size() < k) {
        return -1;
    }
    int piv = a.size() - 1;
    vector<int>menor;
    vector<int> mayor;
    vector<int> iguales;
    for (size_t i = 0; i < a.size() - 1; i++) {
        if (a[i] < a[piv]) {
            menor.push_back(a[i]);
        }
        else if (a[i] > a[piv]) {
            mayor.push_back(a[i]);
        }
        else {
            iguales.push_back(a[i]);
        }

    }
    if (k < menor.size()) {
        return kaesimo(menor, k);
    }
    else if (k > menor.size() + iguales.size()) {
        return kaesimo(mayor, k - menor.size() - iguales.size() - 1);
    }
    else {
        return a[piv];
    }
}

int main() {
    vector<int> i = { 5, 2, 20, 3, 1, 6, 7 ,1,1,1};
    int k = kaesimo(i, 5);
    cout << "el kaesimo: " <<k << endl;
    return 0;
}
