/*

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.



Here choose value of BASE and hash Function carefully




*/

class Solution {
public:
    int strStr(string s, string t) {
        int S = s.length(), T = t.length();

        int m = 1000000033; // or 1e9+7

        int targetcode=0;
        int power = 1;
        for(int i=0;i<T;i++){
            targetcode = (targetcode*26LL + t[i]-'a')%m;
            power = (power*26LL)%m;
        }

        long long hashcode = 0;
        for(int i=0;i<S;i++){
            hashcode = (hashcode*26LL + s[i]-'a')%m;
            if(i<T-1) continue;
            if(i>=T) hashcode = (hashcode - (s[i-T]-'a')*1LL*power + m)%m;

            if(hashcode == targetcode){
                if(s.substr(i-T+1, T) == t) return i-T+1;
            }
        }
        return -1;
    }
};