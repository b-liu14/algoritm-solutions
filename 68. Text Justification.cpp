class Solution {
public:
    string merge(vector<string>& words, int end, int begin, int nAVGSpace, int nUneven) {
        string str = words[begin];
        for (int i = 1; i < end - begin; i ++) {
            for (int j = 0; j < nAVGSpace + (i <= nUneven); j ++) {
                str.push_back(' ');
            }
            str += words[i+begin];
        }
        return str;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int begin = 0;
        int end = 0;
        int lenSum = -1;
        int n = words.size();
        while (end < n) {
            // can insert into this line
            if (lenSum + words[end].length() + 1 <= maxWidth) {
                lenSum = lenSum + words[end].length() + 1;
            }
            else {
                string cur(maxWidth, ' ');
                // just one word?
                if (end == begin + 1) {
                    cur.replace(0, words[begin].length(), words[begin]);
                }
                // justify many words
                else {
                    int nspace = maxWidth - lenSum;
                    int nAVGSpace = nspace / (end - begin - 1) + 1;
                    int nUneven = nspace % (end - begin - 1);
                    cur = merge(words, end, begin, nAVGSpace, nUneven);
                }
                //
                ans.push_back(cur);
                lenSum = words[end].length();
                begin = end;
            }
            end ++;
        }
        // last line
        string lastLine = merge(words, end, begin, 1, 0);
        while (lastLine.length() < maxWidth) {
            lastLine.append(" ");
        }
        ans.push_back(lastLine);
        return ans;
    }
};
