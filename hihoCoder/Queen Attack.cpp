// 80%
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

class point {
public:
    int x, y;
    point(int _x, int _y) : x(_x), y(_y) {};
};

bool canAttack(point A, point B) {
    return (A.x == B.x || A.y == B.y || A.x + A.y == B.x + B.y || A.x - A.y == B.x - B.y);
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<point> v;
    for (int i = 0; i < N; i ++) {
        int x, y;
        cin >> x >> y;
        v.push_back(point(x, y));
    }
    int ans = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = i+1; j < N; j ++) {
            if (canAttack(v[i], v[j])) {
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// nlg(n) 100%
class point {
public:
    int x, y, sum, diff;
    point(int _x, int _y) : x(_x), y(_y) {
        sum = x + y;
        diff = x - y;
    };
};

struct {
    bool operator() (const point& p1, const point& p2) const {
        return p1.x < p2.x;
    }
}  xCmp;

struct {
    bool operator() (const point& p1, const point& p2) const {
        return p1.y < p2.y;
    }
}  yCmp;

struct {
    bool operator() (const point& p1, const point& p2) const {
        return p1.sum < p2.sum;
    }
}  sumCmp;

struct {
    bool operator() (const point& p1, const point& p2) const {
        return p1.diff < p2.diff;
    }
}  diffCmp;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<point> v;
    for (int i = 0; i < N; i ++) {
        int x, y;
        cin >> x >> y;
        v.push_back(point(x, y));
    }

    int ans = 0;

    sort(v.begin(), v.end(), xCmp);
    int nSame = 0;
    for (int i = 1; i < N; i ++) {
        if (v[i].x == v[i-1].x) {
            nSame ++;
            ans += nSame;
        }
        else {
            nSame = 0;
        }
    }

    sort(v.begin(), v.end(), yCmp);
    nSame = 0;
    for (int i = 1; i < N; i ++) {
        if (v[i].y == v[i-1].y) {
            nSame ++;
            ans += nSame;
        }
        else {
            nSame = 0;
        }
    }

    sort(v.begin(), v.end(), sumCmp);
    nSame = 0;
    for (int i = 1; i < N; i ++) {
        if (v[i].sum == v[i-1].sum) {
            nSame ++;
            ans += nSame;
        }
        else {
            nSame = 0;
        }
    }

    sort(v.begin(), v.end(), diffCmp);
    nSame = 0;
    for (int i = 1; i < N; i ++) {
        if (v[i].diff == v[i-1].diff) {
            nSame ++;
            ans += nSame;
        }
        else {
            nSame = 0;
        }
    }

    cout << ans << endl;
    return 0;
}

// o(n)
// class point is same.
int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<point> v;
    for (int i = 0; i < N; i ++) {
        int x, y;
        cin >> x >> y;
        v.push_back(point(x, y));
    }

    int ans = 0;
    unordered_map<int, int> countx;
    unordered_map<int, int> county;
    unordered_map<int, int> countsum;
    unordered_map<int, int> countdiff;
    for (int i = 0; i < N; i ++) {
        countx[v[i].x] ++;
        county[v[i].y] ++;
        countsum[v[i].sum] ++;
        countdiff[v[i].diff] ++;
    }
    for (auto cx: countx) {
        int c = cx.second;
        ans += (c * (c-1)) / 2;
    }
    for (auto cx: county) {
        int c = cx.second;
        ans += (c * (c-1)) / 2;
    }
    for (auto cx: countsum) {
        int c = cx.second;
        ans += (c * (c-1)) / 2;
    }
    for (auto cx: countdiff) {
        int c = cx.second;
        ans += (c * (c-1)) / 2;
    }

    cout << ans << endl;
    return 0;
}
