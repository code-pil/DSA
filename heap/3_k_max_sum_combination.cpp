/*

Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.


*/


vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    priority_queue<pair<int,pair<int,int>>> pq;
    int n = A.size();
    
    vector<int> ans;
    
    pq.push({A[0]+B[0],{0,0}});
    set<pair<int,int>> validate;
    validate.insert({0,0});
    while(C--){
        auto p = pq.top();
        pq.pop();
        
        ans.push_back(p.first);
        
        int i=p.second.first;
        int j=p.second.second;
        
        if(i+1 < n && validate.find({i+1,j}) == validate.end()){
            pq.push({A[i+1]+B[j],{i+1,j}});
            validate.insert({i+1,j});
        }
        
        if(j+1 <n && validate.find({i,j+1}) == validate.end()){
            pq.push({A[i]+B[j+1],{i,j+1}});
            validate.insert({i,j+1});
        }
    }
    return ans;
}
