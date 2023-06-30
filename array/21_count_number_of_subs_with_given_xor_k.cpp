#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int,int> m;
    int xx=0,ans=0;
    // m[xx]++; //for handeling xx==x see i.e codepil
    for(int i=0;i<arr.size();i++){
        xx ^= arr[i];
        if(xx==x) ans++; // codepil
        int p = xx^x;
        ans+=m[p];
        m[xx]++;
    }
    return ans;
}
