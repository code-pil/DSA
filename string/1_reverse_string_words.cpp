/*

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

*/

class Solution {
public:
    string reverseWords(string s) {
        string ans="", tmp="";
        int i=0,n=s.length();
        while(i<n){
            if(s[i] == ' '){
                if(tmp != ""){
                    if(ans != "") ans = tmp + " " + ans;
                    else ans = tmp;
                    tmp="";
                }
            }
            else tmp+=s[i];
            i++;
        }
        if(tmp != ""){
            if(ans != "") ans = tmp + " " + ans;
            else ans = tmp;
        }
        return ans;
    }
};