// O(N^2) brute force
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;

        for (auto w: words) {
            counts[w] ++;
        }
        int n = (int)words.size();
        int l = n ? (int)words[0].size() : 0;
        int slen = (int)s.length();
        vector<int> ans;
        for (int i = 0; i <= slen - n * l; i ++) {
            unordered_map<string, int> seen;
            int j = 0;
            while (j < n){
                int index = i + j * l;
                string word = s.substr(index, l);
                if (counts.count(word) == 0 || seen[word] >= counts[word]) {
                    break;
                }
                else {
                    seen[word] ++;
                }
                j ++;
            }
            if (j == n) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// O(N)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = (int)words.size();
        if (n == 0) {
            return ans;
        }
        int l = (int)words[0].size();
        int slen = (int)s.length();
        unordered_map<string, int> count;
        for (auto w: words) {
            count[w] ++;
        }
        for (int j = 0; j < l; j ++) {
            unordered_map<string, int> seen;
            int left = j;
            for (int i = j; i < slen; i += l) {
                string word = s.substr(i, l);
                if (!count[word]) {
                    left = i + l;
                    seen.clear();
                }
                else {
                    if (seen[word] >= count[word]) {
                        while (s.substr(left, l) != word) {
                            seen[s.substr(left, l)] --;
                            left += l;
                        }
                        seen[s.substr(left, l)] --;
                        left += l;
                    }
                    seen[word] ++;
                    if (i + l - left == n * l) {
                        ans.push_back(left);
                        seen[s.substr(left, l)] --;
                        left += l;
                    }
                }
            }
        }
        return ans;
    }
};
