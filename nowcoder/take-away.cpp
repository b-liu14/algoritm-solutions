//
//  main.cpp
//  nowcoder
//
//  Created by kevin on 13/06/2017.
//  Copyright © 2017 kevin. All rights reserved.
//

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

bool dfs(vector<int>& a, vector<int>& b, vector<bool>&v, vector<bool>& hasCycle, int cur, string& result) {
    if (cur == a.size() - 1) {
        return true;
    }
    else {
        v[cur] = true;
        auto to = cur + a[cur];
        if (to >= 0 && to < a.size()) {
            if (v[to]) {
                hasCycle[to] = true;
            }
            else {
                result += 'a';
                if (dfs(a, b, v, hasCycle, to, result)) return true;
                result.pop_back();
            }
        }

        to = cur + b[cur];
        if (to >= 0 && to < a.size()) {
            if (v[to]) {
                hasCycle[to] = true;
            }
            else {
                result += 'b';
                if (dfs(a, b, v, hasCycle, to, result)) return true;
                result.pop_back();
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<bool> v(n, false);
    vector<bool> hasCycle(n, false);
    string ans = "";
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    auto result = dfs(a, b, v, hasCycle, 0, ans);
    if (result == false) {
        cout << "No solution!" << endl;
    }
    else {
        bool isInf = false;
        int cur = 0;
        for (auto c: ans) {
            if (hasCycle[cur]) {
                isInf = true;
                break;
            }
            cur += (c == 'a' ? a[cur] : b[cur]);
        }
        cout << (isInf ? "Infinity!" : ans) << endl;
    }
    return 0;
}
