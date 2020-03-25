// Submitted version: 70% test cases passed.
// Fixed minor bug based on the submitted version.

#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

enum INDEX_TYPE {
    ROW,
    COL
};

class Node {
public:
    int cnt;
    INDEX_TYPE type;
    int index;
    Node(int _cnt, INDEX_TYPE _type, int _index) {
        cnt = _cnt;
        type = _type;
        index = _index;
    }
    bool operator<(const Node& n) const {
        return cnt > n.cnt;
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> A(n, vector<int>(m));
    vector<int> cnt_row(n, 0), cnt_col(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] != 0) {
                cnt_row[i]++;
                cnt_col[j]++;
            }
        }
    }
    priority_queue<Node> pq;
    for (int i = 0; i < n; i++) {
        if (cnt_row[i] < m && cnt_row[i] > 1) {
            pq.push(Node(cnt_row[i], ROW, i));
        }
    }
    for (int j = 0; j < m; j++) {
        if (cnt_col[j] < n && cnt_col[j] > 1) {
            pq.push(Node(cnt_col[j], COL, j));
        }
    }
    vector<int> ids;
    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        if (node.type == ROW) {
            for (int j = 0; j < m && ids.size() < 2; j++) {
                if (A[node.index][j] > 0) {
                    ids.push_back(j);
                }
            }
            int diff = (A[node.index][ids[1]] - A[node.index][ids[0]]) / (ids[1] - ids[0]);
            for (int j = 0; j < m; j++) {
                if (A[node.index][j] == 0) {
                    A[node.index][j] = A[node.index][ids[0]] + diff * (j - ids[0]);
                    cnt_col[j]++;
                    if (cnt_col[j] < n && cnt_col[j] > 1) {
                        pq.push(Node(cnt_col[j], COL, j));
                    }
                }
            }
        } else {
            for (int i = 0; i < n && ids.size() < 2; i++) {
                if (A[i][node.index] > 0) {
                    ids.push_back(i);
                }
            }
            int diff = (A[ids[1]][node.index] - A[ids[0]][node.index]) / (ids[1] - ids[0]);
            for (int i = 0; i < n; i++) {
                if (A[i][node.index] == 0) {
                    A[i][node.index] = A[ids[0]][node.index] + diff * (i - ids[0]);
                    cnt_row[i]++;
                    if (cnt_row[i] < m && cnt_row[i] > 1) {
                        pq.push(Node(cnt_row[i], ROW, i));
                    }
                }
            }
        }
        ids.clear();
    }

    int x, y;
    for (int k = 0; k < q; k++) {
        cin >> x >> y;
        x--;
        y--;
        if (A[x][y] != 0) {
            cout << A[x][y] << endl;
        } else {
            cout << "Unknown" << endl;
        }
    }
    return 0;
}
