#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <ctime>
using namespace std;
const int Edge = 19;
vector<vector<int> > B(Edge + 2, vector<int>(Edge + 2, 0));
vector<vector<int> > P(Edge + 2, vector<int>(Edge + 2, 0));
vector<vector<int> > E(Edge + 2, vector<int>(Edge + 2, 0));
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
set<vector<vector<int> > > tab;

void initBoard() {
    for(int i = 1; i <= Edge; i++)
        for(int j = 1; j <= Edge; j++)
            B[i][j] = 0;
    tab.clear();
}

int getParent(int x, int y) {
    if(P[x][y] == x * 100 + y) return P[x][y];
    return P[x][y] = getParent(P[x][y] / 100, P[x][y] % 100);
}

void takePawn(int x, int y, bool isBlack) {
    queue<int> q;
    q.push(x * 100 + y);
    while(!q.empty()) {
        int px = q.front() / 100, py = q.front() % 100; q.pop();
        B[px][py] = P[px][py] = E[px][py] = 0;
        for(int i = 0; i < 4; i++) {
            int nx = px + dx[i], ny = py + dy[i];
            if((isBlack && B[nx][ny] == 2) || (!isBlack && B[nx][ny] == 1)) {
                int p = getParent(nx, ny);
                E[p / 100][p % 100]++;
            }
            else if((isBlack && B[nx][ny] == 1) || (!isBlack && B[nx][ny] == 2)) {
                q.push(nx * 100 + ny);
            }
        }
    }
}

void putPawn(int x, int y, bool isBlack) {
    if(B[x][y]) {
        printf("miss 1\n");
        return;
    }
    vector<vector<int> > temB = B, temP = P, temE = E;

    B[x][y] = isBlack ? 1 : 2;
    P[x][y] = x * 100 + y;
    int check[5] = {0};
    int errorNum = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        int &p = check[i];
        if(B[nx][ny] == 0) E[x][y]++;
        else if((isBlack && B[nx][ny] == 1) || (!isBlack && B[nx][ny] == 2)) {
            p = getParent(nx, ny);
            if(x * 100 + y == p) E[x][y]--;
            else {
                E[x][y] += E[p / 100][p % 100] - 1;
                P[p / 100][p % 100] = x * 100 + y;
            }
        }
        else if((isBlack && B[nx][ny] == 2) || (!isBlack && B[nx][ny] == 1)) {
            p = getParent(nx, ny);
            E[p / 100][p % 100]--;
            errorNum++;
        }
    }
    errorNum = 4;
    check[4] = P[x][y];
    for(int i = 0; i < 5; i++) {
        int& p = check[i];
        if(!E[p / 100][p % 100]) {
            if(i == 4) {
                if(errorNum == 4) {
                    printf("miss 2\n");
                    B = temB, P = temP, E = temE;
                    return;
                }
                else takePawn(p / 100, p % 100, isBlack);
            }
            else takePawn(p / 100, p % 100, !isBlack);
        }
    }

    if(tab.find(B) != tab.end()) {
        printf("miss 3\n");
        B = temB, P = temP, E = temE;
    }
    else tab.insert(B);
}

void printBoard() {
    for(int i = 1; i <= Edge; i++) {
        for(int j = 1; j <= Edge; j++) {
            switch(B[i][j]) {
                case 0:
                    printf(".");
                    break;
                case 1:
                    printf("B");
                    break;
                case 2:
                    printf("W");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    char line[100];
    int N, x, y;
    char color;
    bool isBlack;
    while(T--)
    {
        scanf("%d", &N);
        gets(line);
        initBoard();
        while(N--)
        {
            gets(line);
            color = line[0];
            sscanf(&line[2], "%d%d", &x, &y);
            isBlack = color == 'B' ? true : false;
            putPawn(x, y, isBlack);
        }
        printBoard();
    }
    return 0;
}
