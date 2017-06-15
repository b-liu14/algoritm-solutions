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
const int maxn = 100000 + 10;

long long A[maxn], C[maxn], tot, M;
int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        scanf("%lld %lld", &A[i], &A[2*N-i+1]);
        tot += A[i] + A[2*N-i+1];
    }
    M = int(tot / (N*2));
    C[0] = 0;
    for (int i = 1; i < 2*N; i ++) {
        C[i] = C[i-1] + A[i] - M;
    }
    sort(C, C+2*N);
    long long x1 = C[N], ans = 0;
    for (int i = 0; i < 2*N; i ++) {
        ans += abs(x1 - C[i]);
    }
    cout << ans << endl;

    return 0;
}
