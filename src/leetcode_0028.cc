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
        // for(int i = 0; i < pattern.size(); i ++) cout << nxt[i] << " "; cout << endl;
        
        int i = 0, j = 0;
        while(i < text.size()) {
            while(-1 != j && text[i] != pattern[j]) j = nxt[j];
            i ++;
            j ++;
            if(j >= pattern.size()) return i - pattern.size();
        }
        return -1;
    }

    int direct(string haystack, string needle) {
        if (needle.empty()) return 0;
        const int N = haystack.size() - needle.size() + 1;
        for (int i = 0; i < N; i++) {
            int j = i;
            int k = 0;
            while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]) {
                j++;
                k++; 
            }
            if (k == needle.size()) return i;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};