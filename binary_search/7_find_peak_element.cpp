/*
Input: nums = [1,2,1,3,5,6,4]
Output: 5
					6 <-- ans	
				5
						4
			3
	2 <--ans
1		1


if(arr[mid] < arr[mid+1]) ans can be lie on right part

     /\
    /  \
   /
  mid
 /
/

if(arr[mid] > arr[mid+1]) ans can be lie on left part

 /\
/  \
   mid
     \
      \
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int mid = (lo+hi)>>1;

            if(nums[mid] > nums[mid+1]) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};