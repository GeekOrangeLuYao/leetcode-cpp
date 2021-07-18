class Solution {
public:
    string trans(string s) {
        int len = s.length();
        string res = "$";
        for(int i = 0; i < len; i ++) {
            res += '#';
            res += s[i];
        }
        return res + '#';
    }
    int rad[2010];
    string longestPalindrome(string s) {
        if(s.length() == 0) return s;
        s = trans(s);
        memset(rad, 0, sizeof rad);
        int center, res;
        center = res = 0;
        int len = s.length();
        for(int i = 2; i < len; i ++){
            if(rad[center] + center > i) {
                rad[i] = min(rad[2 * center - i], rad[center] + center - i);
            }
            else {
                rad[i] = 1;
            }
            while(s[i - rad[i]] == s[i + rad[i]]) ++ rad[i];
            if(center + rad[center] < i + rad[i]) center = i;
            if(rad[res] < rad[i]) res = i; 
        }
        s = s.substr(res - rad[res] + 1, 2 * rad[res] - 1);
        string ret = "";
        for(auto c: s) {
            if(c == '#' || c == '$') continue;
            ret += c;
        }
        return ret;
    }
};