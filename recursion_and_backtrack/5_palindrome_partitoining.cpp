class Solution {
public:

    bool isPalindrome(string str, int s, int e){
        while(s<=e){
            if(str[s++] != str[e--]) return false;
        }
        return true;
    }

    void partition(string s, vector<vector<string>> &ans, vector<string> &ds, int idx){
        if(idx == s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                ds.push_back(s.substr(idx, i-idx+1));
                partition(s, ans, ds, i+1);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        partition(s, ans, ds, 0);
        return ans;
    }
};
