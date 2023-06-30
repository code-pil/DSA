
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        q.push({startWord, 1});
        unordered_map<string, int> mp;
        
        for(auto str : wordList) mp[str]=1;
        mp[startWord]=0;
        
        int size = wordList[0].length();
        
        //TC: N * word.length * 26
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first;
            int cost = it.second;
            if(word == targetWord) return cost;
            
            for(int i =0;i<size;i++){
                char original = word[i];
                for(int ch ='a';ch<='z';ch++){
                    word[i]=ch;
                    if(mp[word]){
                        q.push({word, cost+1});
                        mp[word]=0;
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};