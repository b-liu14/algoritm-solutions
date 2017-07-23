#define nChild 27
class Trie {
public:
    Trie* childs[nChild]; // a-z and $

    /** Initialize your data structure here. */
    Trie() {
        memset(childs, 0, sizeof(childs));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        word.push_back('z' + 1);
        for (int i = 0; i < word.size(); i ++) {
            Trie* child = node->childs[word[i]-'a'];
            if (! child) {
                child = new Trie();
                node->childs[word[i]-'a'] = child;
            }
            node = child;
        }
    }

    string contains(string str) {
        Trie* node = this;
        string ret;
        for (int i = 0; i < str.size(); i ++) {
            if (node->childs['z'+1-'a']) {
                return ret;
            }
            Trie* child = node->childs[str[i]-'a'];
            ret.push_back(str[i]);
            if (! child) {
                return str;
            }
            node = child;
        }
        return str;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie trie;
        for (auto str: dict) {
            trie.insert(str);
        }
        int begin = 0;
        string ret = "";
        while (begin < sentence.length()) {
            int end = begin;
            while (sentence[end] != ' ') {
                end ++;
            }
            string str = sentence.substr(begin, end-begin);
            if (begin > 0) {
                ret.push_back(' ');
            }
            ret += trie.contains(str);
            begin = end + 1;
        }
        return ret;
    }
};
