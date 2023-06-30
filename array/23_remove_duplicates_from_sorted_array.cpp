class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        int k=0;
        int i=1,j=1;
        while(j<nums.size()){
            while(j<nums.size() && nums[j]==nums[j-1]) j++;
            if(j==nums.size()) return i;
            nums[i]=nums[j];
            i++;j++;
        }
        return i;
    }
};
