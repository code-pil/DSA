/*


You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

----------
Solution:
----------

suppose we have infinite number of operations so we can divide all bag of ball into 1 so --> low =1

we had 0 operations we can't divide bags of ball so --> high = max(v)


search space --> 1 to max(v)

now check for every mid wheather number of operation is as mid is ans < actual operations
we would decrease our ans so --> hi = mid, ans=mid;

else lo = mid+1

*/



class Solution {
public:

    int minimumSize(vector<int>& v, int ops) {
        int lo=1,hi=INT_MIN,ans;
        for(auto ele : v) hi = max(hi, ele);

        while(lo < hi){
            int mid = (lo+hi)>>1;

            int ctOps=0;
            for(int i=0;i<v.size();i++){
                if(v[i] > mid){
                    if(v[i]%mid==0){
                        ctOps += v[i]/mid-1;
                    }
                    else ctOps += v[i]/mid;
                }
            }

            if(ctOps <= ops) hi=mid,ans=mid;
            else lo=mid+1;
        }

        return hi;

    }
};