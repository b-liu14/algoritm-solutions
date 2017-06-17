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

int main(int argc, const char * argv[]) {
    int m = 0;
    string tmp;
    while (cin >> m) {
        getline(cin, tmp);
        bool wrong = false;
        string line;
        for (int i = 1; i <= m; i ++) {
            getline(cin, line);
            if (wrong || line[0] == '?') continue;
            auto should_be = (i % 2 == 1 ? 'I' : 'O');
            // cout << should_be << " = " << line[0] << ": " << wrong << endl;
            wrong = (line[0] != should_be);
            if (wrong) cout << i << endl;
        }
        if (!wrong) {
            cout << -1 << endl;
        }
    }
    return 0;
}
