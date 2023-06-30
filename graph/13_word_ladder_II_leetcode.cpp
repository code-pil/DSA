//Leetcode: https://leetcode.com/problems/word-ladder-ii/description/

class Solution {
    unordered_map<string,int> backtrack;
    vector<vector<string>> ans;
    string b;


private:

    void dfs(string word, vector<string> &seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int ct = backtrack[word];
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;

                if(backtrack[word] and backtrack[word]+1 == ct){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        b = beginWord;
        unordered_map<string,int> mp;

        for(auto word: wordList){
            mp[word]=1;
        }
        mp[beginWord]=0;
        backtrack[beginWord]=1;

        int size = beginWord.size();

        while(!q.empty()){
            auto word = q.front();
            q.pop();
            int ct = backtrack[word];

            if(word == endWord) break;

            for(int i=0;i<size;i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(mp[word]){
                        q.push(word);
                        mp[word]=0;
                        backtrack[word]=ct+1;
                    }
                }
                word[i] = original;
            }
        }

        if(backtrack[endWord]){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        
        return ans;
        
    }
};