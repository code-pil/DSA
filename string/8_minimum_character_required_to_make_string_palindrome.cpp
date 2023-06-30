/*

Given a string A. The only operation allowed is to insert characters at the beginning of the string.
Find how many minimum characters are needed to be inserted to make the string a palindrome string.


Problem Constraints
1 <= |A| <= 106


Input Format
The only argument given is string A.


Output Format
Return the minimum characters that are needed to be inserted to make the string a palindrome string.


Example Input
Input 1:
A = "ABC"
Input 2:
A = "AACECAAAA"


Example Output
Output 1:
2
Output 2:
2


Example Explanation
Explanation 1:
Insert 'B' at beginning, string becomes: "BABC".
Insert 'C' at beginning, string becomes: "CBABC".
Explanation 2:
Insert 'A' at beginning, string becomes: "AAACECAAAA".
Insert 'A' at beginning, string becomes: "AAAACECAAAA".

Solution: 

s = 'abbc'

x = s + '$' + s.reverse() = 'abbc$cbba'
find LPS for x

*/

int lps(string s){
    int n=s.length();
    vector<int> pi(n,0);
    pi[0]=0;
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 and s[i] != s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
    }
    return pi.back();
}

int Solution::solve(string A) {
    string B=A;
    reverse(B.begin(), B.end());
    string s = A + '$' + B;
    return A.length() - lps(s);
}
