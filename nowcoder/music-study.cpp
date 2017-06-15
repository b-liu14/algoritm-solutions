#include <iostream>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cstdlib>
#include <cctype>
#include <stack>

#define INF 1000000000
using namespace std;

int main(int argc, const char * argv[]) {
    int m,n;
    int a[1000+10], b[1000+10];
    cin >> m;
    for (int i = 0; i < m; i ++) {
        cin >> a[i];
    }
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    int dmin = (int)INF;
    for (int i = 0; i <= n-m; i ++) {
        int d = 0;
        for (int j = 0; j < m; j ++) {
            auto diff = a[j] - b[i+j];
            d += diff * diff;
        }
        dmin = min(dmin, d);
    }
    cout << dmin << endl;
    return 0;
}
