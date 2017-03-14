class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> _map;
        int last[s.length()+1];
        int ans = 0;
        int cur = 0;
        for(int i = 0; i < s.length(); i ++){
            char c = s[i];
            last[i] = _map.count(c) == 0 ? -1 : _map[c];
            _map[c] = i;
            cur = min(cur+1, i - last[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};

// short solution
int lengthOfLongestSubstring(string s) {
  vector<int> dict(256, -1);
  int maxLen = 0, start = -1;
  for (int i = 0; i != s.length(); i++) {
      if (dict[s[i]] > start)
          start = dict[s[i]];
      dict[s[i]] = i;
      maxLen = max(maxLen, i - start);
  }
  return maxLen;
}
