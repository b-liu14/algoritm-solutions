bool myfunction (vector<int> i,vector<int> j) { return (i[0]<j[0]); }

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), myfunction);
        vector<vector<int>> vec;
        for (int i = 0; i < pairs.size(); i ++) {
            auto p = pairs[i];
            if (vec.size() == 0 || p[0] > vec.back()[1]) {
                vec.push_back(p);
            }
            else {
                for (int i = 0; i < vec.size(); i ++) {
                    if (vec[i][1] > p[1] && vec[i][0] < p[1]) {
                        vec[i] = p;
                    }
                }
            }
        }
        return (int)vec.size();
    }
};
