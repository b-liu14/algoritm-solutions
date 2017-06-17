//
//  main.cpp
//  coding
//
//  Created by szp on ??/?/?.
//  Copyright © ????年 szp. All rights reserved.
//

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

// 对拍时使用的宏，INCRE为增量式做法，FORCE为暴力版本，RAND为数据生成器，目前FORCE版本AC，INCRE版本还有问题。
#define FORCE

#ifdef INCRE
vector<vector<int> > B(Edge + 2, vector<int>(Edge + 2, 0)), P(Edge + 2, vector<int>(Edge + 2, 0)), E(Edge + 2, vector<int>(Edge + 2, 0));
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
set<vector<vector<int> > > tab;

void initBoard()
{
    for(int i = 0; i < Edge + 2; i++) B[i][0] = B[i][Edge + 1] = E[i][0] = E[i][Edge + 1] = -1;
    for(int j = 0; j < Edge + 2; j++) B[0][j] = B[Edge + 1][j] = E[0][j] = E[Edge + 1][j] = -1;
    for(int i = 1; i <= Edge; i++)
        for(int j = 1; j <= Edge; j++)
            B[i][j] = P[i][j] = E[i][j] = 0;
    tab.clear();
}

int getParent(int x, int y)
{
    if(P[x][y] == x * 100 + y) return P[x][y];
    return P[x][y] = getParent(P[x][y] / 100, P[x][y] % 100);
}

void takePawn(int x, int y, bool isBlack)
{
    queue<int> q;
    q.push(x * 100 + y);
    while(!q.empty())
    {
        int px = q.front() / 100, py = q.front() % 100; q.pop();
        B[px][py] = P[px][py] = E[px][py] = 0;
        for(int i = 0; i < 4; i++)
        {
            int nx = px + dx[i], ny = py + dy[i];
            if((isBlack && B[nx][ny] == 2) || (!isBlack && B[nx][ny] == 1))
            {
                int p = getParent(nx, ny);
                E[p / 100][p % 100]++;
            }
            else if((isBlack && B[nx][ny] == 1) || (!isBlack && B[nx][ny] == 2))
            {
                q.push(nx * 100 + ny);
            }
        }
    }
}

void putPawn(int x, int y, bool isBlack)
{
    if(B[x][y])
    {
        printf("miss 1\n");
        return;
    }
    vector<vector<int> > temB = B, temP = P, temE = E;

    B[x][y] = isBlack ? 1 : 2;
    P[x][y] = x * 100 + y;
    int check[5] = {0};
    int errorNum = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        int &p = check[i];
        if(B[nx][ny] == 0) E[x][y]++;
        else if((isBlack && B[nx][ny] == 1) || (!isBlack && B[nx][ny] == 2))
        {
            p = getParent(nx, ny);
            if(x * 100 + y == p) E[x][y]--;
            else
            {
                E[x][y] += E[p / 100][p % 100] - 1;
                P[p / 100][p % 100] = x * 100 + y;
            }
        }
        else if((isBlack && B[nx][ny] == 2) || (!isBlack && B[nx][ny] == 1))
        {
            p = getParent(nx, ny);
            E[p / 100][p % 100]--;
            errorNum++;
        }
    }
    errorNum = 4;
    check[4] = P[x][y];
    for(int i = 0; i < 5; i++)
    {
        int& p = check[i];
        if(!E[p / 100][p % 100])
        {
            if(i == 4)
            {
                if(errorNum == 4)
                {
                    printf("miss 2\n");
                    B = temB, P = temP, E = temE;
                    return;
                }
                else takePawn(p / 100, p % 100, isBlack);
            }
            else takePawn(p / 100, p % 100, !isBlack);
        }
    }

    if(tab.find(B) != tab.end())
    {
        printf("miss 3\n");
        B = temB, P = temP, E = temE;
    }
    else tab.insert(B);
}

void printBoard()
{
    for(int i = 1; i <= Edge; i++)
    {
        for(int j = 1; j <= Edge; j++)
        {
            switch(B[i][j])
            {
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

int main()
{
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

            cout << line << endl;
            printBoard();
            cout << endl;
        }
        printBoard();
    }
    return 0;
}
#endif

//===================================================================

#ifdef FORCE
vector<vector<int> > B(Edge + 1, vector<int>(Edge + 1, 0));
set<vector<vector<int> > > tab;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void initBoard()
{
    for(int i = 1; i <= Edge; i++)
        for(int j = 1; j <= Edge; j++)
            B[i][j] = 0;
    tab.clear();
}

void printBoard()
{
    for(int i = 1; i <= Edge; i++)
    {
        for(int j = 1; j <= Edge; j++)
        {
            switch(B[i][j])
            {
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

bool dfs(int x, int y, vector<vector<bool> >& vis, const int& color)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= Edge && ny >= 1 && ny <= Edge && !vis[nx][ny])
        {
            if(B[nx][ny] == color)
            {
                vis[nx][ny] = true;
                if(!dfs(nx, ny, vis, color)) return false;
            }
            else if(B[nx][ny] == 0) return false;
        }
    }
    return true;
}

void takePawn(int x, int y, const int& color)
{
    queue<int> q;
    q.push(x * 100 + y);
    while(!q.empty())
    {
        x = q.front() / 100, y = q.front() % 100; q.pop();
        B[x][y] = 0;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= Edge && ny >= 1 && ny <= Edge && B[nx][ny] == color)
                q.push(nx * 100 + ny);
        }
    }
}

void putPawn(int x, int y, bool isBlack)
{
    if(B[x][y])
    {
        printf("miss 1\n");
        return;
    }
    vector<vector<int> > temB = B;
    int color = isBlack ? 1 : 2;
    bool isTaken = false, isEmpty = false;
    B[x][y] = color;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= Edge && ny >= 1 && ny <= Edge)
        {
            vector<vector<bool> > vis(Edge + 1, vector<bool>(Edge + 1, false));
            if(B[nx][ny] == 3 - color)
            {
                vis[nx][ny] = true;
                bool temT = dfs(nx, ny, vis, 3 - color);
                if(temT) takePawn(nx, ny, 3 - color);
                isTaken = isTaken || temT;
            }
            else if(B[nx][ny] == 0) isEmpty = true;
        }
    }
    if(!isTaken && !isEmpty)
    {
        vector<vector<bool> > vis(Edge + 1, vector<bool>(Edge + 1, false));
        isTaken = dfs(x, y, vis, color);
        if(isTaken)
        {
            printf("miss 2\n");
            B = temB;
            return;
        }
    }
    if(tab.find(B) != tab.end())
    {
        printf("miss 3\n");
        B = temB;
    }
    else tab.insert(B);
}

int main()
{
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

            cout << line << endl;
            printBoard();
            cout << endl;
        }
        printBoard();
    }
    return 0;
}
#endif

//=========================================================

#ifdef RAND
int main()
{
    srand(unsigned(time(NULL)));
    int T = 1, N = 1000;
    cout << T << endl;
    for(int i = 0; i < T; i++)
    {
        cout << N << endl;
        for(int j = 0; j < N; j++)
        {
            char color = j & 1 ? 'W' : 'B';
            cout << color << ' ' << rand() % Edge + 1 << ' ' << rand() % Edge + 1 << endl;
        }
    }
    return 0;
}
#endif
