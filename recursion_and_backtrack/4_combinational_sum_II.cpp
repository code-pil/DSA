class Solution {
public:
    vector<vector<int>> ans;
    void combinational_sum(vector<int> candidates, int target, int i, vector<int>& v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int index=i;index<candidates.size();index++){
            if(i<index && candidates[index]==candidates[index-1]) continue;
            if(candidates[index]<=target){
                v.push_back(candidates[index]);
                combinational_sum(candidates,target-candidates[index],index+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        combinational_sum(candidates,target,0,v);
        return ans;
    }
};
