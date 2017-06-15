class Solution {
public:
    string push_single(string s, string t, int N, int start) {
        while(start < s.length()) {
            t.push_back(s[start]);
            start += 2 * (N-1);
        }
        return t;
    }
    string push_double(string s, string t, int N, int start) {
        int cur = start;
        while(cur < s.length()) {
            t.push_back(s[cur]);
            cur = cur + 2 * (N - 1) - 2 * start;
            if (cur < s.length()) {
                t.push_back(s[cur]);
                cur += 2 * start;
            }
            else {
                break;
            }
        }
        return t;
    }
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string t = "";

        t = push_single(s, "", numRows, 0);
        for (int i = 1; i <= numRows-2; i ++) {
            t = push_double(s, t, numRows, i);
        }
        t = push_single(s, t, numRows, numRows-1);

        return t;
    }
};

// concise solution
string convert(string s, int nRows) {
  if(nRows <= 1) return s;
  string result = "";
  //the size of a cycle(period)
  int cycle = 2 * nRows - 2;
  for(int i = 0; i < nRows; ++i)
  {
      for(int j = i; j < s.length(); j = j + cycle){
         result = result + s[j];
         int secondJ = (j - i) + cycle - i;
         if(i != 0 && i != nRows-1 && secondJ < s.length())
             result = result + s[secondJ];
      }
  }
  return result;
}
