// I(1)，V(5)，X(10)，L(50)，C(100)，D(500)，M(1000)
// The most beautiful solution:
class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};
// naive solution
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        // thousand
        while (num >= 1000) {
            ans.push_back('M');
            num -= 1000;
        }
        // hundred
        int h = num / 100;
        if (h == 9) {
            ans.append("CM");
            num -= 900;
        }
        else if (h == 4) {
            ans.append("CD");
            num -= 400;
        }
        else {
            if (h >= 5){
                ans.append("D");
                num -= 500;
            }
            while (num >= 100) {
                ans.append("C");
                num -= 100;
            }
        }

        // ten
        h = num / 10;
        if (h == 9) {
            ans.append("XC");
            num -= 90;
        }
        else if (h == 4) {
            ans.append("XL");
            num -= 40;
        }
        else {
            if (h >= 5){
                ans.append("L");
                num -= 50;
            }
            while (num >= 10) {
                ans.append("X");
                num -= 10;
            }
        }

        // one
        h = num;
        if (h == 9) {
            ans.append("IX");
            num -= 9;
        }
        else if (h == 4) {
            ans.append("IV");
            num -= 4;
        }
        else {
            if (h >= 5){
                ans.append("V");
                num -= 5;
            }
            while (num >= 1) {
                ans.append("I");
                num -= 1;
            }
        }
        return ans;
    }
};
// more concise solution:
class Solution {
public:
    inline int down(int num, string& ans, int base, char one, char five, char ten) {
        int h = num / base;
        if (h == 9) {
            ans.push_back(one);
            ans.push_back(ten);
            num -= 9 * base;
        }
        else if (h == 4) {
            ans.push_back(one);
            ans.push_back(five);
            num -= 4 * base;
        }
        else {
            if (h >= 5){
                ans.push_back(five);
                num -= 5 * base;
            }
            while (num >= base) {
                ans.push_back(one);
                num -= base;
            }
        }
        return num;
    }
    string intToRoman(int num) {
        string ans = "";
        // thousand
        while (num >= 1000) {
            ans.push_back('M');
            num -= 1000;
        }
        // hundred
        num = down(num, ans, 100, 'C', 'D', 'M');
        num = down(num, ans, 10, 'X', 'L', 'C');
        num = down(num, ans, 1, 'I', 'V', 'X');
        return ans;
    }
};
