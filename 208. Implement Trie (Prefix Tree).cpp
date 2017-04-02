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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        word.push_back('z' + 1);
        return startsWith(word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (int i = 0; i < prefix.size(); i ++) {
            Trie* child = node->childs[prefix[i]-'a'];
            if (! child) {
                return false;
            }
            node = child;
        }
        return true;
    }
};
