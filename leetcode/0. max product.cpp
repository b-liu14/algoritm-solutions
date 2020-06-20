// 求小于等于正整数N的所有正整数中，各位数字乘积最大者，如输入220，返回199

#include <vector>
using namespace std;

int max_product(int N) {
    if (N == 0) {
        return 0;
    }
    vector<int> v;
    // get value of each position
    while (N != 0) {
        v.push_back(N % 10);
        N /= 10;
    }
    // preprocess zero
    for (int i = v.size() - 2; i >= 0; --i) {
        if (v[i] == 0) {
            int k = i + 1;
            v[k]--;
            while (v[k] == 0 && k + 1 < v.size()) {
                v[k] = 9;
                v[k + 1]--;
                k += 1;
            }
            // remove lead zero
            if (v[k] == 0 && k + 1 == v.size()) {
                v.pop_back();
            }
            // set right part to 9
            for (int j = i; j >= 0; --j) {
                v[j] == 0;
            }
            break;
        }
    }
    // run
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] * v[i + 1] < 9 * (v[i + 1] - 1)) {
            v[i] = 9;
            v[i + 1]--;
        }
    }
    if (v.back() == 0) {
        }
}

int main() {
}