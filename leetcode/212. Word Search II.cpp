class Trie {
public:
    Trie* childs[26];
    string* word;

    Trie() {
        memset(childs, 0, sizeof(childs));
        this->word = nullptr;
    }

    Trie(vector<string>& words) {
        memset(childs, 0, sizeof(childs));
        this->word = nullptr;
        for (int i = 0; i < words.size(); i ++) {
            Trie* node = this;
            for (int j = 0; j < words[i].size(); j ++) {
                int index = words[i][j] - 'a';
                if (node->childs[index] == nullptr) node->childs[index] =  new Trie();
                node = node->childs[index];
            }
            node->word = &(words[i]);
        }
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, Trie* root, int x, int y, vector<string>& ret) {
        char c = board[x][y];
        if (board[x][y] == '$' || root->childs[c - 'a'] == nullptr) return;
        root = root->childs[c - 'a'];
        if (root->word) {
            ret.push_back(*(root->word));
            root->word = nullptr;
        }
        board[x][y] = '$'; // $ for visited
        if (x > 0) dfs(board, root, x-1, y, ret);
        if (y > 0) dfs(board, root, x, y-1, ret);
        if (x < board.size()-1) dfs(board, root, x+1, y, ret);
        if (y < board[0].size() - 1) dfs(board, root, x, y+1, ret);
        board[x][y] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        Trie* root = new Trie(words);
        for (int x = 0; x < board.size(); x ++) {
            for (int y = 0; y < board[0].size(); y ++) {
                dfs(board, root, x, y, ret);
            }
        }
        return ret;
    }
};
