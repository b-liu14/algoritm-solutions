//
//  main.cpp
//  hihocoder
//
//  Created by kevin on 06/04/2017.
//  Copyright © 2017 kevin. All rights reserved.
//

// 样例程序
// https://hihocoder.com/help-center/coder-help#judge-result

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
using namespace std;

#define INT_MAX 1000000000000

int main(int argc, const char * argv[]) {
    long long N, Q;
    cin >> N >> Q;
    long long ans = INT_MAX;
    long long t_before = INT_MAX;

    for (int x = 1; x <= N; x ++) {
        long long k = ceil(log2(float(x)));
        long long t1 = Q * k;
        long long N1 = N - (pow(2, (float)k) - x) * Q;
        long long t = t1 + ceil(float(N1)/x);
        if (t > t_before) {
            break;
        }
        ans = min(ans, t);
        t_before = t;
    }

    cout << ans << endl;
    return 0;
}

// AC
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define INF 1000000000000

int main() {
    long long N;
    int Q;
    cin >> N >> Q;
    long long t = INF;
    long long x = 1;
    long long count = 0;
    while (x < N) {
        t = min(t, (long long)ceil((float(N)/x)) + count * Q);
        count ++;
        x <<= 1;
    }
    cout << t << endl;
}
