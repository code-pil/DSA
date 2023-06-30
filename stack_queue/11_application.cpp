// Leetcode: https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> histo(m, 0);
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '0') histo[j] = 0;
                else histo[j] += matrix[i][j]-'0';
            }
            maxArea = max(maxArea, findMaxAreaHisto(histo));
        }
        return maxArea;
    }

    int findMaxAreaHisto(vector<int> &histo){
        stack<int> st;
        int area = 0;
        for(int i=0;i<=histo.size();i++){
            while(!st.empty() and (i==histo.size() or histo[st.top()] > histo[i])){
                int w;
                int h = histo[st.top()];
                st.pop();
                if(st.empty()) w = i;
                else w = i-1-st.top();
                area = max(area, w*h);
            }
            st.push(i);
        }
        return area;
    }
};

/*

1   1
1 0 1 1 1
1 1 1 1 1 

*/