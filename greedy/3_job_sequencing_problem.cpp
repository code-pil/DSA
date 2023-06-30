#include <bits/stdc++.h> 

bool comp(vector<int> a, vector<int> b){
    if(a[1]>b[1]) return true;
    return false;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),comp);
    int maxi=0;
    for(auto ele : jobs){
        maxi = max(maxi, ele[0]);
    }
    int slots[maxi+1];
    memset(slots,-1,sizeof(slots));
    int job_ct=0, pro=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i][0];j>0;j--){
            if(slots[j]==-1){
                slots[j]=i;
                job_ct++;
                pro+=jobs[i][1];
                break;
            }
        }
    }
    return pro;
}

