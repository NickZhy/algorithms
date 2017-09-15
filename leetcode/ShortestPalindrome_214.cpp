// Violent search.
class Solution {
public:
    bool isPalindrome(string &s, int end) {
        int i = 0, j = end;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        int end = s.size() - 1;
        while(!isPalindrome(s, end)){
            --end;
        }
        string prefix = "";
        for(int i = end + 1; i<s.size(); ++i) {
            prefix += s[i];
        }
        reverse(prefix.begin(), prefix.end());
        return prefix + s;
    }
};

// Convert the problem to: finding longest match suffix-prefix(not the whole string).
class Solution {
public:
    int KMPTable(string& str) {
        string tmp = str;
        reverse(tmp.begin(), tmp.end());
        tmp = str + "/n" + tmp;
        
        vector<int> table(tmp.size(), 0);
        for(int pos = 1, maxPreSuff = 0; pos<tmp.size(); ++pos) {
            while(maxPreSuff > 0 && tmp[pos] != tmp[maxPreSuff])
                maxPreSuff = table[maxPreSuff - 1];
            if(str[maxPreSuff] == tmp[pos])
                ++maxPreSuff;
            table[pos] = maxPreSuff;
        }
        return table[tmp.size()-1];
    }
    
    string shortestPalindrome(string s) {
        int len = KMPTable(s);
        string prefix = "";
        while(len < s.size()) {
            prefix += s[len++];
        }
        reverse(prefix.begin(), prefix.end());
        return prefix + s;
    }
};

