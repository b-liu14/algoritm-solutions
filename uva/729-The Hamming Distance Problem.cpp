#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int M, N, H;
    cin >> M;
    for (int i = 0; i < M; i ++) {
        cin >> N >> H;
        for (int j = 0; j < (1 << N); j ++) {
            int cnt = 0, tmp = j;
            string ret(N, '0');
            for (int k = 0; tmp > 0 && k < N; k ++) {
                if (tmp % 2) {
                    cnt ++;
                    ret[N - k - 1] = '1';
                }
                tmp = (tmp >> 1);
            }
            if (cnt == H) cout << ret << endl;
        }
        if (i < M - 1) cout << endl;
    }
    return 0;
}
