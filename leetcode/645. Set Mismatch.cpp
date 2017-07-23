class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> s;
        set<int> s1;
        for (int i = 0; i < nums.size(); i ++) {
            s1.insert(i+1);
        }
        int miss, dup = -1;
        for (auto num: nums) {
            if (s.find(num) != s.end()) {
                dup = num;
            }
            else {
                s.insert(num);
                s1.erase(num);
            }
        }
        vector<int> ret;
        ret.push_back(dup);
        ret.push_back(*s1.begin());
        return ret;
    }
};
