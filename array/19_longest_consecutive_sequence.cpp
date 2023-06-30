#include<bits/stdc++.h>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto ele : nums) s.insert(ele);
        int ans=0;
        for(auto ele : nums){
            if(s.find(ele-1) == s.end()){
                int ct=0,x=ele;
                while(s.find(ele++) != s.end()) ct++;
                ans = max(ans,ct);
            }
        }
        return ans;
    }
};
