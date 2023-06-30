//combinatorics solution
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	int N = m+n-2,r=min(m,n)-1;
	int ans=1;
	for(int i=1;i<=r;i++){
		ans = ans * (N-i+1)/i;
	}
	return (int)ans;
}


//second dp solution
class Solution {
public:
    int dp[101][101];
    int path(int m, int n, int x, int y){
        if(m==x && n==y){
            return 1;
        }
        if(dp[x][y]!=-1) return dp[x][y];
        if(m<x || n<y) return 0;
        return dp[x][y]=path(m,n,x+1,y)+path(m,n,x,y+1);
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return path(m-1, n-1, 0, 0);
    }
};
