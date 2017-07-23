class Edge {
public:
    int pos;
    bool isleft;
    Edge(int _pos, bool _isleft): pos(_pos), isleft(_isleft) {};
    bool operator < (const Edge e) const {
        return pos < e.pos || (pos == e.pos && isleft);
    }
};

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if (wall.size() == 0 || wall[0].size() == 0) {
            return 0;
        }
        priority_queue<Edge> pq;
        for (int i = 0; i < wall.size(); i ++) {
            int pos = 0;
            for (int j = 0; j < wall[i].size() - 1; j ++) {
                pos += wall[i][j];
                pq.push(Edge(pos, true));
                pq.push(Edge(pos, false));
            }
        }
        int cur = (int)wall.size();
        int ans = cur;
        while (!pq.empty()) {
            Edge tmp = pq.top();
            pq.pop();
            if (tmp.isleft) cur ++;
            else cur --;
            ans = min(ans, cur);
        }
        return ans;
    }
};
