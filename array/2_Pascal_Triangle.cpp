#define pb push_back

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].pb(1);
        for(int i=1;i<numRows;i++) {
            for(int j=0;j<=i;j++) {
                if(j==0 || j==i) {
                    ans[i].pb(1);
                }
                else {
                    ans[i].pb(ans[i-1][j]+ans[i-1][j-1]);
                }
            }
        }
        return ans;
    }
};
