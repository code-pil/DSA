// GFG: https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_map<string, int> mp;
        for(auto str : wordList){
            mp[str]=1;
        }
        mp[beginWord]=0;
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<string> usedOnLevel = {beginWord};
        vector<vector<string>> ans;
        int level = 1;
        
        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            
            if(vec.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    mp[it]=0;
                }
                
            }
            
            string word = vec.back();
            
            if(word == endWord){
                ans.push_back(vec);
                continue;
            }
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(mp[word]){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};
