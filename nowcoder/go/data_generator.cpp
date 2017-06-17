#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// data_generator.cp
const int Edge = 19;
int get_rand() {
  return rand() % Edge + 1;
}
int main() {
    srand(unsigned(time(NULL)));
    int T = 1, N = 1000;
    cout << T << endl;
    for(int i = 0; i < T; i++) {
        cout << N << endl;
        for(int j = 0; j < N; j++) {
            char color = j & 1 ? 'W' : 'B';
            cout << color << ' ' << get_rand() << ' ' << get_rand() << endl;
        }
    }
    return 0;
}
