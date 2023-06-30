#include <bits/stdc++.h> 

long long merge(long long *arr, int l, int mid, int r){
    int i=l;
    int j=mid;
    int inv_ct=0;
    int temp[r-l+1];
    int k=0;
    while(i<mid && j<=r){
        if(arr[i] < arr[j]) temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv_ct += (mid-i);
        }
    }
    while(i<mid) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];

    for(int p=0;p<r-l+1;p++) arr[p+l]=temp[p];

    return inv_ct;
}

long long mergesort(long long *arr, int l, int r){
    int inv_ct=0;
    if(r>l){
        int mid = (l+r)/2;
        inv_ct += mergesort(arr, l, mid);
        inv_ct += mergesort(arr, mid+1, r);

        inv_ct += merge(arr, l, mid+1, r);
    }
    return inv_ct;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergesort(arr, 0,n-1);
}
