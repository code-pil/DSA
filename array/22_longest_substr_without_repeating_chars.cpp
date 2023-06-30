//approach 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> m;
        int ans=0,j=0,i=0;
        while(j<s.length()){
            m[s[j]]++;
            if(m.size()==j-i+1) ans=max(ans,j-i+1);
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(!m[s[i]]) m.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};


//approach 2: 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> m;
        int l=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                l=max(m[s[i]]+1,l);
            }
            m[s[i]]=i;
            ans=max(ans,i-l+1);     
        }
        return ans;
    }
};
