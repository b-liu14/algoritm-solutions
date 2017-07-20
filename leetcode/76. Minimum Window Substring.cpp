// TWO POINTS
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) {
            map[c]++;
        }
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end < s.size()){
            char c = s[end];
            end ++;
            if (map[c] > 0) {
                counter --;
            }
            map[c] --;
            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - begin;
                }
                if (map[s[begin]] == 0) {
                    counter ++;
                }
                map[s[begin]] ++;
                begin ++;
            }
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};
