/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (29.29%)
 * Likes:    3214
 * Dislikes: 1174
 * Total Accepted:    432.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 *
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list.
 *
 *
 * Note:
 *
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: 0
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 *
 *
 *
 *
 */

#include<queue>
#include<set>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string> unseen(wordList.begin(), wordList.end());

        q.push(make_pair(beginWord, 1));

        while (!q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (word == endWord) {
                return dist;
            }

            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                for (word[i] = 'a'; word[i] <= 'z'; word[i]++) {
                    if (word[i] == c) {
                        continue;
                    }
                    if (unseen.find(word) != unseen.end()) {
                        q.push(make_pair(word, dist + 1));
                        unseen.erase(word);
                    }
                }
                word[i] = c;
            }
        }

        return 0;
    }
};
// @lc code=end

int main() {
    vector<string> v= {"a", "b", "c"};
    Solution s;
    cout << s.ladderLength("a", "c", v);
}
