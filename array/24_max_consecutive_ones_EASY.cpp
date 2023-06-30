class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct=0,maxi=0;
        for(auto ele : nums){
            if(ele==1) ct++;
            else ct=0;
            if(ct>maxi) maxi = ct;
        }
        return maxi;
    }
};
