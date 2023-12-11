#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




vector<int> secuenciass(const vector<int>& V) {
    int n = V.size();
    vector<int> lis(n, 1);
    vector<int> prev(n, -1);

    int endIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (V[i] > V[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }

        if (lis[i] > lis[endIndex]) {
            endIndex = i;
        }
    }

    vector<int> result;
    while (endIndex != -1) {
        result.push_back(V[endIndex]);
        endIndex = prev[endIndex];
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> V = { 11, 17, 5, 8, 6, 4, 7, 12, 3 };

   
    vector<int> secuencias = secuenciass(V);


    cout << "secuencia mmx: ";
    for (int num : secuencias) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
