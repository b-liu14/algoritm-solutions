// AC

#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int min3(int a, int b, int c) {
    return min(min(a, b), c);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<long long>> dp(3, vector<long long>(n, 0));
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < 3; i++) {
            dp[i][j] = min3(
                dp[0][j - 1] + abs(a[0][j - 1] - a[i][j]),
                dp[1][j - 1] + abs(a[1][j - 1] - a[i][j]),
                dp[2][j - 1] + abs(a[2][j - 1] - a[i][j]));
        }
    }
    cout << min3(dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]);
    return 0;
}