/*

Given k sorted array of different size merge them into one array.

solution: 
using priority Q push all first elements of k array with their array index like --> {arr[i][0], i}
now pop top element of Q and push next element from that array (that's why we push pair in Q)

*/

// Priority Queue Approach
/*
    Time Complexity: O((N * K) * log(K)) 
    Space Complexity: O(N * K)
    
    Where N is the total number of elements in all the arrays, and K is the number of arrays.
*/




#include <bits/stdc++.h> 

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0], i});
    }
    vector<int> idx(k,0);

    vector<int> ans;
    while(!pq.empty()){
        auto ele = pq.top();
        pq.pop();

        ans.push_back(ele.first);
        if(idx[ele.second]+1<arr[ele.second].size()){
            pq.push({arr[ele.second][idx[ele.second]+1], ele.second});
            idx[ele.second]+=1;
        }
    }
    return ans;
}

/*

Divide and conqure method

    Time Complexity: O((N * K) * log(K))
    Space Complexity: O((N * K )* log(K))
    
    Where K is the number of arrays and N is the average number of elements in every array. 
*/

#include <bits/stdc++.h> 

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> ans;
    int n=a.size(), m=b.size();
    int i=0,j=0;

    while(i<n && j<m){
        if(a[i]<b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }
    while(i<n) ans.push_back(a[i++]);
    while(j<m) ans.push_back(b[j++]);

    return ans;
}

vector<int> mergeKSortedArraysHelper(vector<vector<int>> arr, int lo, int hi){
    if(lo==hi) return arr[lo];

    if(lo+1==hi) return merge(arr[lo],arr[hi]);

    // int mid = lo + (hi-lo)>>1;// This line gives TLE in codestudio
    int mid = lo + (hi - lo)/2;

    vector<int> x = mergeKSortedArraysHelper(arr, lo, mid);
    vector<int> y = mergeKSortedArraysHelper(arr, mid+1, hi);

    return merge(x, y);
}

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    vector<int> ans = mergeKSortedArraysHelper(arr, 0, k-1);
    return ans;
}

