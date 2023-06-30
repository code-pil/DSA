class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1=0,ct2=0,e1,e2,n=nums.size();
        for(int i=0;i<n;i++){
            if(ct1==0 && e2 != nums[i]) e1=nums[i],ct1++;
            else if(ct2==0 && e1 != nums[i]) e2=nums[i],ct2++;
            else if(nums[i]==e1) ct1++;
            else if(nums[i]==e2) ct2++;
            else ct1--,ct2--;
        }
        ct1=0,ct2=0;
        for(auto ele : nums) {
            if(ele == e1) ct1++;
            else if(ele == e2) ct2++;
        }
        vector<int> ans;
        if(ct1>n/3) ans.push_back(e1);
        if(ct2>n/3) ans.push_back(e2);

        return ans;
    }
};
