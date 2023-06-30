/*

Leetcode : https://leetcode.com/problems/next-greater-element-i/description/

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Version I

*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size(),-1);

        stack<int> st;

        for(int i=0;i<nums2.size();i++){
            while(!st.empty() and nums2[i] > nums2[st.top()]){
                nge[st.top()] = i;
                st.pop(); 
            }
            st.push(i);
        }

        unordered_map<int,int> mp;

        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = nge[i];
        }
        

        vector<int> ans;

        for(auto ele : nums1){
            int idx = mp[ele];
            if(idx != -1)
                ans.push_back(nums2[idx]);
            else ans.push_back(-1);
        }

        return ans;
    }
};


// Version II , circular
/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order 
next in the array, which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.
*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> nge(nums.size(), -1);

        for(int i=0;i<2*nums.size();i++){
            while(!st.empty() and nums[i%nums.size()] > nums[st.top()%nums.size()]){
                nge[st.top()%nums.size()] = nums[i%nums.size()];
                st.pop();
            }
            st.push(i);
        }

        return nge;

    }
};