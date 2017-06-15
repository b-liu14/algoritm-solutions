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
    int m = 0, n;
    cin >> n;
    int score = 0;
    cin >> score;
    for (int i = 1; i < n; i ++) {
        int tmp;
        cin >> tmp;
        if (tmp <= score) {
            m ++;
        }
    }
    cout << int(floor(log2(m+1)+1e-5)) << endl;
    return 0;
}
