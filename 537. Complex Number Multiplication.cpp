typedef pair<int, int> comp;
class Solution {
public:
    comp fromString(string a) {
        int tmp = a.substr(1).find("+") + 1;
        string r = a.substr(0, tmp);
        string i = a.substr(tmp+1, a.length() - tmp - 2);
        return make_pair(stoi(r), stoi(i));
    }
    string toString(comp a) {
        return to_string(a.first) + "+" + to_string(a.second) + "i";
    }
    string complexNumberMultiply(string a, string b) {
        comp c1 = fromString(a);
        comp c2 = fromString(b);
        comp c3;
        c3.first = c1.first * c2.first - c1.second * c2.second;
        c3.second = c1.first * c2.second + c1.second * c2.first;
        return toString(c3);
    }
};
