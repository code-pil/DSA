
/*

Problem: https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

YT: https://www.youtube.com/watch?v=3tAB663q-nk


*/


#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> v, int n) {
    // Write your code here.
    vector<int> pse(n, -1);
    vector<int> nse(n, n);

    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() and v[i] < v[st.top()]){
            nse[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and v[i] < v[st.top()]){
            pse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> ans(n,INT_MIN);

    for(int i=0;i<n;i++){
        ans[nse[i]-pse[i]-2] = max(ans[nse[i]-pse[i]-2], v[i]);
    }

    for(int i=n-2;i>=0;i--){
        ans[i] = max(ans[i], ans[i+1]);
    }

    return ans;
}