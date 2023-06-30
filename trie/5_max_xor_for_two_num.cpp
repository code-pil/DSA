//leetcode: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

struct Node{
    Node* link[2];
    bool containKey(int bit){
        return link[bit] != NULL;
    }
    Node* get(int bit){
        return link[bit];
    }
    void put(int bit, Node* node){
        link[bit] = node;
    }
};

class Trie{
private: 
    Node* root;
public: 
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containKey(1-bit)){
                maxNum = maxNum | 1<<i;
                node = node->get(1-bit);
            }
            else node = node->get(bit);
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto ele : nums) trie.insert(ele);
        int ans = 0;
        for(auto ele : nums){
            ans = max(ans, trie.getMax(ele));
        }
        return ans;
    }
};