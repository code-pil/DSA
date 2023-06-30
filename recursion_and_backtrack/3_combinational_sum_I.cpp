class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int>& candidates, int i, vector<int>& v, int target){
        if(target==0) {
            ans.push_back(v);
            return;
        }
        if(i==candidates.size()) return;
        if(target>=candidates[i]){
            v.push_back(candidates[i]);
            func(candidates,i,v,target-candidates[i]);
            v.pop_back();
        }
        func(candidates,i+1,v,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        func(candidates,0,v,target);
        return ans; 
    }
};
