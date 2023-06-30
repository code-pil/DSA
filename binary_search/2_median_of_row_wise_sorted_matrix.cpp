#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> v, int ele){
    int lo=0;
    int hi=v.size()-1;

    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(v[mid]<=ele) lo=mid+1;
        else hi = mid-1;
    }
    return lo;
}


int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int lo=1;
    int hi=1e9;
    int n=matrix.size(), m=matrix[0].size();

    while(lo<=hi){
        int mid = (lo+hi)>>1;
        int ct=0;
        for(int i=0;i<n;i++){
            // ct += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            ct += upperBound(matrix[i], mid);
        }
        if(ct <= (n*m)>>1) lo = mid+1;
        else hi = mid-1;
    }

    return lo;
}
