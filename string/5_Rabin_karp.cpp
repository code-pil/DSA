/*

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2


*/

class Solution {
public:
    int m = 1e9+7;


    /*
    Hash Function:
        'abc' = (((97)*31+98)*31+99)

    */
    
    int RabinKarp(string s, string t){
        if(s=="" or t=="") return -1;
        int S = s.length(), T = t.length();

        long long int power=1;
        for(int i=0;i<T;i++){
            power = (power*31LL)%m;
        }

        long long int targetcode = 0;
        for(int i=0;i<T;i++){
            targetcode = (targetcode*31LL + t[i])%m;
        }

        long long int hashcode = 0;

        for(int i=0;i<S; i++){
            hashcode = (hashcode*31LL + s[i])%m;
            if(i<T-1) continue;
            if(i>=T) hashcode = (hashcode-s[i-T]*power)%m;
            if(hashcode<0) hashcode+=m;
            if(hashcode == targetcode){
                if(s.substr(i-T+1, T) == t) return 1;
            }
        }
        return -1;

    }

    /*
    Hash Function: 
        'abc' = 97*(31^0)+98*(31^1)+99*(31^2)

    */

    int rabinKarp(string s, string t){
        int S = s.length(), T = t.length();
        vector<int> hashOfS(S+1, 0);
        
        long long power = 1;
        for(int i=0;i<S;i++){
            hashOfS[i+1] = (hashOfS[i]+(s[i]*1LL*power))%m;
            power = (power*31LL)%m;
        }

        power = 1;
        long long targetHash=0;
        for(int i=0;i<T;i++){
            targetHash = (targetHash + (t[i]*1LL*power))%m;
            power = (power*31LL)%m;
        }

        power=1;
        for(int i=0;i<S-T+1;i++){
            long long curHash = (hashOfS[i+T]-hashOfS[i]+m)%m;
            if(curHash == (targetHash*1LL*power)%m){
                if(s.substr(i,T) == t){
                    return 1;
                }
            }
            power = (power*31LL)%m;
        }
        return -1;
    }

    int repeatedStringMatch(string s, string t) {
        
        string source = s;
        int ct=1;
        while(source.length() < t.length()){
            source += s;ct++;
        }
        if(source == t) return ct;

        if(rabinKarp(source, t) != -1) return ct;
        if(rabinKarp(source+s, t) != -1) return ct+1;

        return -1;

    }
};