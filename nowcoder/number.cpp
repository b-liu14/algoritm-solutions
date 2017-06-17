#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

vector<long long> sum(long long r) {
    vector<long long> ans(10, 0);
    for(int i = 1; i <= 9; i++) {
        long long n = i;
        for(int j = 1; j <= 10; j++) {
            if(n > r) break;
            long long maxN = min(r, (i + 1) * (n / i) - 1);
          	// n 较大时更加变化的位置求解
            if(n >= 100000) {
                long long left = r / n, right = r / maxN;
                for(long long k = left; k >= right; k--) {
                    ans[i] += k * (min(maxN, r / k) - max(n - 1, r / (k + 1)));
                }
            }
            // n 较小时枚举
            else {
                for(long long k = n; k <= maxN; k++) ans[i] += r / k;
            }
            n = n * 10;
        }
    }
    return ans;
}

int main() {
    int l, r;
    cin >> l >> r;
    vector<long long> L = sum(l - 1), R = sum(r);
    for(int i = 1; i <= 9; i++) cout << R[i] - L[i] << endl;
    return 0;
}
