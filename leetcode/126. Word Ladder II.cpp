class Solution {
public:
    void dfs(vector<list<int>>& ret, vector<vector<bool>>& connect1, int curPos, vector<int>& dis, list<int>& curList) {
        if (dis[curPos] == 0) {
            curList.push_front(curPos);
            ret.push_back(curList);
            curList.pop_front();
            return;
        }
        curList.push_front(curPos);
        for (int i = 0; i < connect1.size(); i ++) {
            if (connect1[i][curPos] && dis[i] == dis[curPos] - 1) {
                dfs(ret, connect1, i, dis, curList);
            }
        }
        curList.pop_front();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // preprocess
        int n = wordList.size();
        wordList.push_back(beginWord);
        vector<vector<bool>> connect(n+1, vector<bool>(n+1, false));
        for (int i = 0; i < n+1; i ++) {
            for (int j = 0; j < n+1; j ++) {
                int count = 0;
                for (int l = 0; l < endWord.size(); l ++) {
                    if (wordList[i][l] != wordList[j][l]) {
                        count ++;
                    }
                    if (count > 1) {
                        break;
                    }
                }
                if (count == 1) {
                    connect[i][j] = true;
                    connect[j][i] = true;
                }
            }
        }

        // dijkstra
        vector<int> dis(n+1, INT_MAX);
        dis[n] = 0;
        queue<int> pq;
        pq.push(n);
        while (! pq.empty()) {
            auto top = pq.front();
            pq.pop();
            if (wordList[top] == endWord) {
                break;
            }
            for (int i = 0; i < n; i ++) {
                if (connect[i][top] && dis[i] > dis[top] + 1) {
                    pq.push(i);
                    dis[i] = dis[top] + 1;
                }
            }
        }

        // get result
        vector<list<int>> pos;
        vector<vector<string>> ret;
        list<int> curList;
        int endPos = -1;
        for (int i = 0; i < n; i ++) {
            if (wordList[i] == endWord) {
                endPos = i;
                break;
            }
        }
        if (endPos == -1) {
            return ret;
        }
        dfs(pos, connect, endPos, dis, curList);
        for (int i = 0; i < pos.size(); i ++) {
            vector<string> tmp;
            for (auto p: pos[i]) {
                tmp.push_back(wordList[p]);
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};
