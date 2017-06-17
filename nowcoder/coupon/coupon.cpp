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
const int maxx = 100000;
const int maxn = maxx + 10;
using namespace std;

int main(int argc, const char * argv[]) {
    int m = 0;
    string tmp;
    while (cin >> m) {
        getline(cin, tmp);
        vector<int> I(maxn, -1);
        vector<int> O(maxn, -1);
        vector<pair<char, int> > record(1, {' ', 0});
        set<int> coupons;
        set<int> unkown;
        int lastPos = 0;
        bool wrong = false;
        string line;
        for (int i = 1; i <= m; i ++) {
            getline(cin, line);
            if (wrong) continue;
            if (line[0] == '?') {
                record.push_back({'?', 0});
                unkown.insert(i);
            }
            else {
                int x = stoi(line.substr(2));
                coupons.insert(x);
                record.push_back({line[0], x});
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
                            record[*iter] = {'O', x};
                            I[x] = i;
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
                            record[*iter] = {'I', x};
                            O[x] = i;
                        }
                    }
                }
                if (wrong) {
                    lastPos = i;
                }
            }
        }
        if (coupons.size() < maxx) {
            cout << (wrong ? lastPos : -1) << endl;
            continue;
        }
        if (!wrong) {
            lastPos = m + 1;
        }
        set<int> haveI, allI, haveO;
        int lastO = lastPos, i = 1;
        while(i < lastPos) {
            while(i < lastPos && record[i].first != '?') {
                if(record[i].first == 'I') haveI.insert(record[i].second);
                else haveI.erase(record[i].second);
                i++;
            }
            i++;
            allI = haveI;
            haveO.clear();
            lastO = i;
            set<int> temHaveI = haveI;

            while(i < lastPos && record[i].first != '?') {
                if(record[i].first == 'I') {
                    allI.insert(record[i].second);
                    temHaveI.insert(record[i].second);
                }
                else {
                    temHaveI.erase(record[i].second);
                    if(haveI.find(record[i].second) != haveI.end() &&
                       haveO.find(record[i].second) == haveO.end()) {
                        haveO.insert(record[i].second);
                        lastO = i;
                    }
                }
                i++;
            }
            i++;

            if(allI.size() >= maxx && haveO.size() >= haveI.size()) {
                lastPos = lastO;
                break;
            }

            haveI = temHaveI;
        }
        cout << (lastPos == m + 1 ? -1 : lastPos) << endl;
    }
    return 0;
}
