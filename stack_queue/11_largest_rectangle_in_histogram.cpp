
/*


Given an array of integers heights representing the histogram's bar height where the 
width of each bar is 1, return the area of the largest rectangle in the histogram.



*/

//In Brute Force Approach run loops for left and right smaller elements

// Left smaller and Right smaller (Next smaller concept)
// TC : O(3*N) SC : O(3*N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftSmaller(n,0);
        vector<int> rightSmaller(n,n-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[i] < heights[st.top()]){
                rightSmaller[st.top()]=i-1;
                st.pop();
            }
            st.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[i] < heights[st.top()]){
                leftSmaller[st.top()]=i+1;
                st.pop();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,(rightSmaller[i]-leftSmaller[i]+1)*heights[i]);
        }
        return ans;
    }
};


//One pass solution


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int area = 0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n or heights[i] < heights[st.top()])){
                int width;
                int height = heights[st.top()];
                st.pop();
                if(st.empty()) width = i;
                else width = i-1-st.top();
                area = max(area, width*height);
            }
            st.push(i);
        }
        return area;
    }
};