//GFG: https://practice.geeksforgeeks.org/problems/maximum-and-value-1587115620/1

class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        // Your code here
        int res = 0;
        for(int shift=31;shift>=0;shift--){
            res |= (1<<shift);
            int ct = 0;
            for(int i=0;i<N;i++){
                if((arr[i] & res) == res) ct++;
            }
            if(ct<=1) res ^= (1<<shift);
        }
        return res;
    }
};