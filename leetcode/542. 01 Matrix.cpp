// my solution using bellman-ford algorithm
class Solution {
public:
    priority_queue<int, std::vector<int>, std::greater<int>> q;
    vector<vector<int>> dist;
    int h;
    int w;
    int INF = INT_MAX / 2;
    int fourMin(int i, int j) {
        while(!q.empty()) {
            q.pop();
        }
        q.push(getDist(i, j-1));
        q.push(getDist(i-1, j));
        q.push(getDist(i, j+1));
        q.push(getDist(i+1, j));
        int ans = q.top();
        return ans;
    }
    int getDist(int i, int j) {
        if (i < 0 || i >= h || j < 0 || j >= w) {
            return INF;
        }
        return dist[i][j];
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        h = (int)matrix.size();
        if (h == 0) {
            return matrix;
        }
        w = (int)matrix[0].size();
        dist = vector<vector<int>>(h, vector<int>(w, INF));
        for (int i = 0; i < h; i ++) {
            for (int j = 0; j < w; j ++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                }
            }
        }
        bool updated = true;
        while (updated) {
            updated = false;
            for (int i = 0; i < h; i ++) {
                for (int j = 0; j < w; j ++) {
                    int minDist = 1 + fourMin(i, j);
                    if (minDist < dist[i][j]) {
                        dist[i][j] = minDist;
                        updated = true;
                    }
                }
            }
        }
        return dist;
    }
};

// solution using BFS from affah
class Solution {
public:
    vector<vector<int>> d;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        d.clear();
        vector<int> line;
        line.resize(matrix[0].size());
        d.resize(matrix.size(), line);
        int n = matrix.size(), m = matrix[0].size();
        typedef pair<int, int> pii;
        queue<pii> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == 0)
                {
                    d[i][j] = 0;
                    q.push(pii(i, j));
                }
                else
                    d[i][j] = 1 << 22;
        while(!q.empty())
        {
            pii c = q.front(); q.pop();
            int x = c.first, y = c.second;
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
            for(int i = 0; i < 4; i++)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if(tx >= 0 && tx < n && ty >= 0 && ty < m && d[tx][ty] == (1 << 22))
                {
                    d[tx][ty] = d[x][y] + 1;
                    q.push(pii(tx, ty));
                }
            }
        }
        return d;
    }
};
