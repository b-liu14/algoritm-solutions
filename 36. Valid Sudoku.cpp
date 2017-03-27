class Solution {
public:
    bool valid(vector<char>& nums) {
        set<int> s;
        for (auto c: nums) {
            if (c != '.') {
                if (s.find(c) != s.end()) {
                    return false;
                }
                s.insert(c);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> nums;
        // row valid
        for (int i = 0; i < 9; i ++) {
            if (!valid(board[i])) {
                return false;
            }
        }
        // column valid
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                nums.push_back(board[j][i]);
            }
            if (!valid(nums)) {
                return false;
            }
            nums.clear();
        }
        // subcell valid
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                nums.push_back(board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3]);
            }
            if (!valid(nums)) {
                return false;
            }
            nums.clear();
        }
        return true;
    }
};
