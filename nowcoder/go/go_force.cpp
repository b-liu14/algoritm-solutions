// go_force.cpp
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
vector<vector<int> > B(Edge + 1, vector<int>(Edge + 1, 0));
set<vector<vector<int> > > tab;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void initBoard() {
    for(int i = 1; i <= Edge; i++)
        for(int j = 1; j <= Edge; j++)
            B[i][j] = 0;
    tab.clear();
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

bool dfs(int x, int y, vector<vector<bool> >& vis, const int& color) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= Edge && ny >= 1 && ny <= Edge && !vis[nx][ny]) {
            if(B[nx][ny] == color) {
                vis[nx][ny] = true;
                if(!dfs(nx, ny, vis, color)) return false;
            }
            else if(B[nx][ny] == 0) return false;
        }
    }
    return true;
}

void takePawn(int x, int y, const int& color) {
    queue<int> q;
    q.push(x * 100 + y);
    while(!q.empty()) {
        x = q.front() / 100, y = q.front() % 100; q.pop();
        B[x][y] = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= Edge && ny >= 1 && ny <= Edge && B[nx][ny] == color)
                q.push(nx * 100 + ny);
        }
    }
}

void putPawn(int x, int y, bool isBlack) {
  	// 已经有子
    if(B[x][y]) {
        printf("miss 1\n");
        return;
    }
    vector<vector<int> > temB = B;
    int color = isBlack ? 1 : 2;
    bool isTaken = false, isEmpty = false;
    B[x][y] = color;
  	// 是否可以提掉周围的子
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= Edge && ny >= 1 && ny <= Edge) {
            vector<vector<bool> > vis(Edge + 1, vector<bool>(Edge + 1, false));
            if(B[nx][ny] == 3 - color) {
                vis[nx][ny] = true;
                bool temT = dfs(nx, ny, vis, 3 - color);
                if(temT) takePawn(nx, ny, 3 - color);
                isTaken = isTaken || temT;
            }
            else if(B[nx][ny] == 0) isEmpty = true;
        }
    }
  	// 不可落子
    if(!isTaken && !isEmpty) {
        vector<vector<bool> > vis(Edge + 1, vector<bool>(Edge + 1, false));
        isTaken = dfs(x, y, vis, color);
        if(isTaken) {
            printf("miss 2\n");
            B = temB;
            return;
        }
    }
  	// 局面重复？
    if(tab.find(B) != tab.end()) {
        printf("miss 3\n");
        B = temB;
    }
    else tab.insert(B);
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
