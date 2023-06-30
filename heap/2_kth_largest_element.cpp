/*
--------------
 Quick Select
--------------

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.


Solution:

Here we use technique of quick sort algorithm
select pivot element and finding its position in array 
if pivot index == k return element

if pivot index > k --> means our answer lies in left part
else answer lies in right part

now find pivot index for left or right part

*/


class Solution {
public:

    int partition(vector<int>& v, int lo, int hi){
        int pivot = v[lo];
        int low = lo;
        lo += 1;
        while(lo<=hi){
            if(v[lo] < pivot && v[hi] > pivot){
                swap(v[lo], v[hi]);
                lo++;
                hi--;
            }
            if(v[lo]>=pivot) lo++;
            if(v[hi]<=pivot) hi--;
        }
        swap(v[low], v[hi]);
        return hi;
    } 

    int findKthLargest(vector<int>& nums, int k) {
        int lo=0, hi=nums.size()-1,kth;

        while(1){
            int pivot = partition(nums, lo, hi);

            if(pivot == k-1){
                kth = nums[pivot];
                break;
            }

            if(pivot >= k-1) hi = pivot-1;
            else lo = pivot+1;
        }

        return kth;
    }
};