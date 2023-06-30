class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=nums[0];
        vector<int> v,vec;
        for(auto ele : nums){
            sum += ele;
            v.push_back(ele);
            if(sum>ans){
                ans = sum;
                vec=v;
            }
            if(sum<0) sum=0,v.clear();
        }
        for(auto ele : vec) cout << ele << " ";
        return ans;
    }
};
