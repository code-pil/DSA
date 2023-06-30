//Leetcode: https://leetcode.com/problems/single-number-iii/description/
//similar problem find missing and repeating number in array 1<= num[i] <= n;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XOR = 0;
        for(auto num : nums) XOR = XOR^num;
        // long long diffBit = XOR & (-XOR);
        long long diffBit = XOR & (~(XOR-1));
        int num1 = 0, num2 = 0;
        for(auto num : nums){
            if(diffBit & num) num1 = num1^num;
            else num2 = num2^num;
        }
        return {num1, num2};
    }
};