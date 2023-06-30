//codestudio : https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1

#include <bits/stdc++.h> 
struct Node{
    Node* list[26];
    bool flag = false;

    bool containKey(char ch){
        return list[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        list[ch-'a'] = node;
    }
    Node* get(char ch){
        return list[ch-'a'];
    }
    bool setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
private: Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfPrefixExists(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd() == false) return false;
            }
            else return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(int i=0;i<n;i++){
        trie.insert(a[i]);
    }

    string ans = "";

    for(auto& s: a){
        if(trie.checkIfPrefixExists(s)){
            if(s.length() > ans.length()) ans = s;
            else if(s.length() == ans.length() and s < ans){
                ans = s;
            }
        }
    }

    return ans==""?"None":ans;
}