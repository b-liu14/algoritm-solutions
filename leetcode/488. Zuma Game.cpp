class Solution {
public:
    string reduce(string board, int pos) {
        int begin = pos - 1, end = pos + 1;
        while (begin >= 0 && board[begin] == board[pos]) {
            begin --;
        }
        while (end < board.length() && board[end] == board[pos]) {
            end ++;
        }
        if (end - begin > 3) {
            string new_board = board.substr(0, begin+1) + board.substr(end);
            board = reduce(new_board, begin);
        }
        return board;
    }
    void dfs(string board, string hand, int cur, int& ans) {
        if (cur >= ans) return;
        if (board == "") {
            ans = cur;
            return;
        }

        for (int i = 0; i < hand.size(); i ++) {
            if (i > 0 && hand[i] == hand[i-1]) continue;
            for (int j = 0; j < board.size(); j ++) {
                if (j > 0 && board[j] == board[j-1]) continue;
                if (board[j] == hand[i]) {
                    string new_hand = hand.substr(0, i) + hand.substr(i+1);
                    string new_board = board.substr(0, j);
                    new_board.push_back(hand[i]);
                    new_board += board.substr(j);
                    dfs(reduce(new_board, j), new_hand, cur+1, ans);
                }
            }
        }
    }
    int findMinStep(string board, string hand) {
        int ans = INT_MAX;
        dfs(board, hand, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};
