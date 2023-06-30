//Leetcode Intiution: https://leetcode.com/problems/single-number-ii/editorial/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int loner = 0;
        for(int shift=0;shift<32;shift++){
            int bitSum = 0;
            for(int num: nums){
                bitSum += (num>>shift)&1;
            }
            int lonerBit = bitSum%3;
            loner = loner | (lonerBit<<shift);
        }
        return loner;
    }
};