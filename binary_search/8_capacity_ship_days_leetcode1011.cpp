/*
Same problem as Allocate books so max pages should be minimum
*/

class Solution {
public:

    bool isPossible(vector<int> w, int capacity, int days){
        int ct=1,totalLoad=0;
        for(auto weight : w){
            totalLoad+=weight;
            if(totalLoad > capacity){
                ct++;
                totalLoad=weight;
            }
        }

        return ct<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo=0;
        int hi=0;
        for(int i=0;i<weights.size();i++){
            lo=max(lo,weights[i]);
            hi+=weights[i];
        }

        while(lo<hi){
            int mid = (lo+hi)>>1;

            if(isPossible(weights, mid, days)){
                hi=mid;
            }
            else lo=mid+1;
        }
        return lo;
    }
};