class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int len = n+m;
        int gap = len/2 +len%2;
        while(gap>0){
            int l=0,r=gap;
            while(r<len){
                //arr1 & arr2
                if(l<n && r>=n){
                    if(arr1[l] > arr2[r-n]) swap(arr1[l],arr2[r-n]);
                }
                //arr2 & arr2
                else if(l>=n) {
                    if(arr2[l-n] > arr2[r-n]) swap(arr2[l-n],arr2[r-n]);
                }
                //arr1 && arr1
                else{
                    if(arr1[l] > arr1[r]) swap(arr1[l],arr1[r]);
                }
                l++,r++;
            }
            if(gap==1) break;
            gap = gap/2 + gap%2;
        }
        for(int i=0;i<m;i++){
            arr1[i+n] = arr2[i];
        }
    }
};
