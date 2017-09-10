class Solution {
public:
    int dist2(vector<int>& p1, vector<int>& p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> len = {dist2(p1, p2), dist2(p1, p3), dist2(p1, p4),
                           dist2(p2, p3), dist2(p2, p4), dist2(p3, p4)};
        sort(len.begin(), len.end());
        return (len[0] > 0 && len[0] == len[3] && len[4] == len[5] && len[4] == len[3] * 2);
    }
};
