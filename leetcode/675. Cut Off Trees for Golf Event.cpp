class PointWithPriority {
public:
    int priority, x, y;
    PointWithPriority(int _priority, int _x, int _y): priority(_priority), x(_x), y(_y) {};
    bool operator < (const PointWithPriority& p) const {
        return priority < p.priority;
    }
};


class Solution {
public:
    // in bfs, Point.h is -(distance from start to point)
    int bfs(vector<vector<int>>& forest, PointWithPriority start, PointWithPriority end) {
        vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size(), false));
        priority_queue<PointWithPriority> pq;
        start.priority = 0;
        pq.push(start);
        visited[start.x][start.y] = true;
        while (! pq.empty()) {
            PointWithPriority cur = pq.top();
            pq.pop();
            if (cur.x == end.x && cur.y == end.y) {
                return -cur.priority;
            }
            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int new_x = cur.x + dx[i];
                int new_y = cur.y + dy[i];
                if (new_x >= 0 && new_x < forest.size() && new_y >= 0 && new_y < forest[0].size()
                    && forest[new_x][new_y] > 0 && visited[new_x][new_y] == false) {
                    visited[new_x][new_y] = true;
                    pq.push(PointWithPriority(cur.priority-1, new_x, new_y));
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<PointWithPriority> vec;
        for (int i = 0; i < forest.size(); i ++) {
            for (int j = 0; j < forest[0].size(); j ++) {
                if (forest[i][j] > 1) {
                    vec.push_back(PointWithPriority(forest[i][j], i, j));
                }
            }
        }
        sort(vec.begin(), vec.end());
        PointWithPriority start(0, 0, 0);
        int ans = 0;
        for (int i = 0; i < (int)vec.size(); i ++) {

            int dist = bfs(forest, start, vec[i]);
            if (dist == -1) {
                return -1;
            }
            ans += dist;
            start = vec[i];
        }
        return ans;
    }
};
