#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }

class node {
public:
    node *p;
    vector<node*> childs;
    long long c, in, ip;
    node(vector<long long>& v) {
        in = v[1];
        ip = v[2];
        c = v[3];
        p = nullptr;
    }
};

long long dfs(node* root) {
    vector<long long> tab(vector<long long>(root->in + 1, INF));
    tab[0] = 0;
    for (auto c: root->childs) {
        long long costAll = dfs(c);
        for (long long j = root->in; j > 0 ; j --) {
            tab[j] = min(tab[max(0, j-c->ip)] + costAll, tab[j]);
        }
    }
    return tab[root->in] + root->c;
}

int main(int argc, const char * argv[]) {
    long long N;
    cin >> N;
    vector<vector<long long>> v(N, vector<long long>(4, 0));
    for (long long i = 0; i < N; i ++) {
        for (long long j = 0; j < 4; j ++) {
            cin >> v[i][j];
        }
    }
    // insert
    node* root = NULL;
    vector<node*> i2node(N, NULL);
    for (long long i = 0; i < N; i ++) {
        node* cur = new node(v[i]);
        i2node[i] = cur;
        if (v[i][0] == 0) {
            root = cur;
        }
        for (long long j = 0; j < i; j ++) {
            if (v[j][0] - 1 == i) {
                cur->childs.push_back(i2node[j]);
                i2node[j]->p = cur;
            }
            if (v[i][0] - 1 == j) {
                cur->p = i2node[j];
                i2node[j]->childs.push_back(cur);
            }
        }
    }
    // dfs
    long long ans = dfs(root);
    cout << (ans < INF ? ans : -1) << endl;
    return 0;
}
