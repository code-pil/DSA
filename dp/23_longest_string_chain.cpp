//leetcode: https://leetcode.com/problems/longest-string-chain/description/

class Solution {
public:
    bool static comp(string a, string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n+1, 1);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i], words[j]) and dp[i]<dp[j]+1){
                    dp[i] = 1+dp[j];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    bool check(string &a, string &b){
        if(a.length() != b.length()+1) return false;
        int i=0, j=0;
        while(i<a.length()){
            if(a[i] == b[j]) i++, j++;
            else i++;
        }
        if(i!=a.length() or j!=b.length()) return false;
        return true;
    }
};