#define nChild 27
class WordDictionary {
public:
    WordDictionary* childs[nChild];
    /** Initialize your data structure here. */
    WordDictionary() {
        memset(childs, 0, sizeof(childs));
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        // recursive version
        WordDictionary* child = NULL;
        if (word.size() == 0) {
            child = new WordDictionary();
            childs[nChild-1] = child;
        }
        else {
            child = childs[word[0]-'a'];
            if (!child) {
                child = new WordDictionary();
                childs[word[0]-'a'] = child;
            }
            child->addWord(word.substr(1));
        }
        // non recursive version
        // WordDictionary* node = this;
        // word.push_back('z' + 1);
        // for (int i = 0; i < word.size(); i ++) {
        //     int index = word[i]-'a';
        //     WordDictionary* child = node->childs[index];
        //     if (!child) {
        //         child = new WordDictionary();
        //         node->childs[index] = child;
        //     }
        //     node = child;
        // }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (word.size() == 0) {
            return childs[nChild-1] != NULL;
        }
        if (word[0] == '.') {
            for (int i = 0; i < nChild - 1; i ++) {
                if (childs[i] && childs[i]->search(word.substr(1))) {
                    return true;
                }
            }
            return false;
        }
        WordDictionary* node = childs[word[0]-'a'];
        return (node != NULL) && node->search(word.substr(1));
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
