class Solution {
public:

    void permutations(vector<int>& nums, vector<vector<int>> &ans, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            permutations(nums, ans, idx+1);
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, ans, 0);
        return ans;
    }
};
