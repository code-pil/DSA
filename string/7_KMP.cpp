class Solution {
public:
    int strStr(string s, string t) {
        //KMP
        // LPS - Longest Prefix Suffix
        int S = s.length(), T = t.length();

        vector<int> pi(T,0);

        pi[0]=0;
        for(int i=1;i<T;i++){
            int j = pi[i-1];
            while(j>0 and t[i] != t[j]) j = pi[j-1];
            if(t[i]==t[j]) j++;
            pi[i] = j;
        }
        
        int pos=-1;
        int i(0), j(0);
        while(i<S){
            if(s[i]==t[j]) i++,j++;
            else{
                if(j!=0) j = pi[j-1];
                else i++;
            }
            if(j == T){
                pos = i-T;
                break;
            }
        }
        return pos;
    }
};