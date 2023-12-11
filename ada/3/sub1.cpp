#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



string subsecuencia(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();


    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));


    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[m][n];
    string result(length, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[--length] = X[i - 1];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    return result;
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";

   
    string subsequence =subsecuencia(X, Y);

    cout << "Subsecuencia común más larga: " << subsequence << endl;

    return 0;
}
