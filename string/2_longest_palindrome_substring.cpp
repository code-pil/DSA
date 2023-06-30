
/*

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

DP:
    0 1 2 3 4
    b a b a d
0 b 1 0 1 0 0
1 a 0 1 0 1 0
2 b 0 0 1 0 0
3 a 0 0 0 1 0
4 d 0 0 0 0 1



*/

// dp solution
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[1000][1000]={0};
        int p=0,q=0;
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) dp[i][i+1]=true,p=i,q=i+1;
        }
        for(int diff=2;diff<n;diff++){
            for(int i=0;i<n-diff;i++){
                int j=i+diff;
                if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j]=true;
                    p=i,q=j;
                }
            }
        }
        string ans;
        for(int i=p;i<=q;i++) ans+=s[i];
        return ans;
    }
};

//Exapand solution
/*

string: ababd

l
r
ababd
ans: a

 l
 r
ababd
ans: a

l r
ababd
ans: aba

  l
  r
ababd
ans: aba

 l r
ababd
ans: aba or bab

l   r
ababd
ans: aba or bab


*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int resLen=0,n=s.length();

        for(int i=0;i<n;i++){

            int l=i,r=i;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>resLen){
                    ans = s.substr(l,r-l+1);
                    resLen = r-l+1;
                }
                l--,r++;
            }

            l=i,r=i+1;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>resLen){
                    ans = s.substr(l,r-l+1);
                    resLen = r-l+1;
                }
                l--,r++;
            }
        }
        return ans;
    }
};