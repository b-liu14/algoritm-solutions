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
const int maxn = 500000 + 10;
using namespace std;

int main(int argc, const char * argv[]) {
    int m = 0;
    string tmp;
    while (cin >> m) {
        getline(cin, tmp);
        vector<int> I(maxn, -1);
        vector<int> O(maxn, -1);
        set<int> unkown;
        bool wrong = false;
        string line;
        for (int i = 1; i <= m; i ++) {
            getline(cin, line);
            if (wrong) continue;
            if (line[0] == '?') {
                unkown.insert(i);
            }
            else {
                int x = stoi(line.substr(2));
                if (line[0] == 'I') {
                    if (I[x] <= O[x]) {
                        I[x] = i;
                    }
                    else {
                        auto iter = unkown.lower_bound(I[x]);
                        if (iter == unkown.end()) {
                            wrong = true;
                        }
                        else {
                            unkown.erase(iter);
                        }
                    }
                }
                else {
                    if (I[x] > O[x]) {
                        O[x] = i;
                    }
                    else {
                        auto iter = unkown.lower_bound(O[x]);
                        if (iter == unkown.end()) {
                            wrong = true;
                        }
                        else {
                            unkown.erase(iter);
                        }
                    }
                }
                if (wrong) {
                    cout << i << endl;
                }
            }
        }
        if (! wrong) {
            cout << -1 << endl;
        }
    }
    return 0;
}
