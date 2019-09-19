#include <stack>
#include <queue>
#include <iostream>
using namespace std;

static const string op2str[] = {"ADD", "SUB", "MUL", "DIV", "DUP"};
class State {
public:
    static const int ADD = 0;
    static const int SUB = 1;
    static const int MUL = 2;
    static const int DIV = 3;
    static const int DUP = 4;
    std::vector<int> ops; // 0: ADD, 1: SUB, 2: MUL, 3: DIV, 4: DUP
    stack<int> st;
    State(int n) { ops.clear(); st.push(n); }
    bool operate(int op) {
        if (op == 4) st.push(st.top());
        else {
            if (st.size() < 2 || (op == DIV && st.top() == 0)) return false;
            int a, b, n;
            a = st.top(); st.pop();
            b = st.top(); st.pop();
            switch (op) {
                case ADD: n = b + a; break;
                case SUB: n = b - a; break;
                case MUL: n = b * a; break;
                case DIV: n = b / a; break;
            }
            if (abs(n) > 3000) return false;
            st.push(n);
        }
        ops.push_back(op);
        return true;
    }
};

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a >> b;
        State state(a);
        queue<State> q;
        q.push(state);
        while (! q.empty()) {
            state = q.front();
            q.pop();
            if (state.st.top() == b) {
                for (int i = 0; i < state.ops.size(); i ++) {
                    cout << op2str[state.ops[i]] << " ";
                }
                cout << endl;
                break;
            }
            for (int i = 0; i < 5; i ++) {
                State tmp = state;
                if (tmp.operate(i)) q.push(tmp);
            }
        }
    }
    return 0;
}
