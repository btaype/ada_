#include <iostream>
#include <vector>


using namespace std;

vector<int> mergesort(vector<int>a) {
    if (a.size() <= 1) {
        return a;
    }
    else {
        int n = a.size() / 2;
        vector<int> a1(a.begin(), a.begin() + n);
        vector<int> a2(a.begin() + n, a.end());
        a1 = mergesort(a1);
        a2 = mergesort(a2);
        int i1 = 0;
        int i2 = 0;
        vector<int> t;
        for (; i1< a1.size() && i2 < a2.size();) {
            if (a1[i1] < a2[i2]) {
                t.push_back(a1[i1]);
                i1++;

            }
            else {
                t.push_back(a2[i2]);
                i2++;
            }
        }
        while (i1 < a1.size()) {
            t.push_back(a1[i1]);
            i1++;
        }
        while (i2 < a2.size()) {
            t.push_back(a2[i2]);
            i2++;
        }
        return t;
    }

}

int main() {
    vector<int > t1 = { 190,10,7,4,3,9,23,3,6 ,56};
    t1 = mergesort(t1);
    for (size_t u = 0; u < t1.size(); u++) {
        cout << t1[u] << " ";
    }
    return 0;
}
