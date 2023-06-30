// codestudio : https://www.codingninjas.com/studio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    int endCount = 0;
    int prefixCount = 0;

    bool containKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void increasePrefix(){
        prefixCount++;
    }
    void increaseEnd(){
        endCount++;
    }
    void deleteEnd(){
        endCount--;
    }
    void reducePrefix(){
        prefixCount--;
    }
    int getEnd(){
        return endCount;
    }
    int getPrefix(){
        return prefixCount;
    }
};

class Trie{

    public:
    Node* root;
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){

                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            node = node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};
