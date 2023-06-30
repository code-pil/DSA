class Solution {
public:

    int mergesort(vector<int>& arr, int lo, int mid, int hi){
        int inv=0;
        int j=mid+1;
        for(int i=lo;i<=mid;i++){
            while(j<=hi && arr[i] > 2LL*arr[j]) j++;
            inv += (j-(mid+1));
        }
        int temp[hi-lo+1];
        int i=lo,k=0;
        j=mid+1;
        while(i<=mid && j<=hi){
            if(arr[i]<arr[j]) temp[k++]=arr[i++];
            else temp[k++]=arr[j++];
        }
        while(i<=mid) temp[k++]=arr[i++];
        while(j<=hi) temp[k++]=arr[j++];
        for(int i=lo;i<=hi;i++){
            arr[i]=temp[i-lo];
        }
        return inv;
    }

    int merge(vector<int>& arr, int lo, int hi){
        int inv=0;
        if(lo<hi){
            int mid = lo + (hi-lo)/2;
            inv += merge(arr, lo, mid);
            inv += merge(arr, mid+1, hi);
            inv += mergesort(arr, lo, mid, hi);
        }
        return inv;
    }

    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size()-1);
    }
};
