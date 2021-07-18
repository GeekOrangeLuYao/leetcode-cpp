# Manacher 算法
求最长回文串

## 1. 预处理
首先字符串可以做一个预处理，例如字符串`abcdcba`可以补充为`#a#b#c#d#c#b#a#`这样就可以把字符串总是补齐成一个奇数长度的字符串。同时一般会在开始的位置补充一个`$`，也就是`$#a#b#c#d#c#b#a#`。

一个简单的实现如下：
```cpp
string trans(string s){
    int len = s.length();
    string ch;
    ch += '$';
    for(int i = 0;i < len;i++){
        ch += '#';
        ch += a[i];
    }
    return ch;
}
```

## 2. 算法核心
首先需要介绍几个概念：
1. 回文数组半径
`rad[id]`数组用来记录以位置为id为回文中心求出的回文半径长度，也就是`[id - rad[id]: id + rad[id]]`是以id为中心的最长的回文串。
2. 最右回文右边界
`right[id]`数据用来表示这个位置及之前的位置为中心的回文子串，所到达的最右边的地方。
3. 最右回文右边界的对称中心
`center[id]`数组表示上面所说可以到达最优的回文串的回文中心。

这个概念可以比较绕，我们给一个例子：
```
index    0 1 2 3 4 5 6 7 8 9 .....
string   $ # a # b # a # b # c # b # d # s #
rad      0 0 1 0 3 0 3 0 1 0 3 0 1 0 1 0 1 0
right    0 1 3 3 7 7 9 ...
center   0 1 2 2 4 4 6 ...
```
可以显然的看到right数组是一个不降的数组。

那么从坐向右的过程分为两种情况：
1. 如果说下一次的index超过来当前right边界，那么就按照正常的策略左右两个指针扩展，并更新right。
2. 如果说下一次的index仍然在right之内，我们假定这个点为p1，从当前的center做轴对称一定有p2：
    1. `center[index] * 2 - right[index] < rad[p2]`相当于center的这个最长回文子串完全包含p2为中心的最长回文子串，那么显然p1为中心的最长回文子串也在其中。那么`rad[p1] = rad[p2]`
    2. 如果`center[index] * 2 - right[index] > rad[p2]`相当于center的边界就是p1的边界，所以`rad[p1] = right[index] - index + 1`
    3. 如果`center[index] * 2 - right[index] == rad[p2]` 相当于是p2的限制使得center不能扩展了，所以这个时候还是需要重新尝试一下。

## 代码实现
在实现的时候，可以将center变为单个向量：
```cpp
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
```
