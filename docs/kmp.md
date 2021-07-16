# KMP 算法

简略的讲一下KMP算法。字符串匹配算法是查找文本串（text）中是否有模式串（pattern），以及其位置。

## 1. 暴力解法
暴力解法非常简单，查看每一个开始的位置，然后跑一边模式串的长度做匹配即可。
```cpp
int direct(string text, string pattern) {
    if (pattern.empty()) return 0;
    const int N = text.size() - pattern.size() + 1; // 所有可能的开始位置
    for (int i = 0; i < N; i++) {
        int j = i;
        int k = 0;
        while (j < text.size() && k < pattern.size() && text[j] == pattern[k]) {
            j++;
            k++; 
        }
        if (k == pattern.size()) return i;
    }
    return -1;
}
```
可以容易分析出效率是`O(m * n)`。


## 2. KMP算法
### 2.1 简单思路
那么暴力算法的问题在哪里呢？我们查看这样的例子：
```
text:    a a a a a a a a a a a a a b
pattern: a a a b
```
那么显然暴力匹配算法存在一个显然的问题：**在最后一个字符串失败的时候，那么前面所有的匹配都浪费了。**
对于已经匹配过的字符串，这些信息已经获得了，那么如何获得、如何利用这个信息呢？
```
text: ************* a a a a a *********
pattern:            a a a b
location:           1 2 3 4 5
bruce next_match:     a a a b
bruce pattern ptr:    |
bruce text prt:       |
kmp next_match:       a a a b
kmp pattern ptr:            |
kmp text ptr:               |
```
在匹配到位置4的时候，失败了，暴力的方法是两个指针回到2位置，但是实际上不需要，因为在匹配的过程中，知道`p[1:3] == t[1:3]`已经匹配了，那么当来到下一个位置的时候，注意到出`p[1:2] == p[2:3]`（只和pattern有关，所以可以预先处理出来），因此完全没有重新匹配2，3位置，只需要重新比较4这个位置是否可以就好了。

上面就是一个基本的KMP的思路，那么核心就是要计算所有的下标长度，使得`p[0: next[i]] == p[i - next[i]: i]`注意这个next要取最大的值。这样，在匹配的过程中，text指针就不需要回退了，pattern指针从`i`位置到`next[i] + 1`。因为前面已经匹配好了。

## 2.2 预处理next数组
那么如何求这个next数组呢？实际上就是pattern和pattern进行匹配的过程。
我们以串`abcabcabcd`为例
* 首先`next[0] == -1`，因为第一个位置失配，那么直接文本串指针向后取一次匹配即可。注意等于-1是为了保持每次循环，模式串指针都`+1`。
* 那么对于`i > 0`时，我们假设此时`next[0, i-1]`全都计算出来了，分两种情况讨论：
    * 如果说`x[i] == x[j]`：相当于是当前字符可以和之前的最长前缀所接的串匹配，因此直接`next[i] = next[j]`
    * 否则的话，不断的向前调整可以匹配的`j`，`j = next[j]`一直到`-1`为止，表示第一个字符也匹配不上。

我们来看一下`abcabcabcd`这个pattern例子：
输入字符串"abcabcabcd"，求`next[]`数据：

前三个字符没有问题：
```
index  0   1   2
next  -1  -1  -1
```
到了`index = 3`，注意`x[0:1] == x[3:4]`:
```
index  0   1   2   3
next  -1  -1  -1   0
```
那么后续的也是一样：
```
index  0   1   2   3   4   5   6   7   8   9
next  -1  -1  -1   0   1   2   3   4   5  -1
```

一个常用的代码如下：
```cpp
void kmp_pre(char x[], int m, int next[]){
    int i, j;
    j = next[0] = -1;
    i = 0;
    while (i < m){
        while (-1 != j && x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
}
```

### 2.3 匹配字符串
看一下经典的`strStr()`，正如我们前面说的:
```cpp
class Solution {
public:
    int nxt[50010];
    void make_nxt(string pattern) {
        int i = 0, j = -1;
        nxt[0] = -1;
        while(i < pattern.size()) {
            while(j > -1 && pattern[j] != pattern[i]) j = nxt[j];
            nxt[++i] = ++j;
        }
    }

    int kmp(string text, string pattern) {
        if(pattern.empty()) return 0;
        
        make_nxt(pattern);
        
        int i = 0, j = 0;
        while(i < text.size()) {
            while(-1 != j && text[i] != pattern[j]) j = nxt[j];
            i ++;
            j ++;
            if(j >= pattern.size()) return i - pattern.size();
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};
```

