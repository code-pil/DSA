// Leetcode: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

struct Node{
    Node* list[2];
    bool containKey(int bit){
        return list[bit] != NULL;
    }
    void put(int bit, Node* node){
        list[bit] = node;
    }
    Node* get(int bit){
        return list[bit];
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

    int query(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else node = node->get(bit);
        }
        return maxNum;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int q = queries.size();
        vector<int> ans(q, -1);
        multimap<pair<int,int>, int> oflineQueries;
        for(int i=0;i<q;i++){
            oflineQueries.insert({{queries[i][1], queries[i][0]}, i});
        }

        Trie trie;
        int index = 0;
        for(auto [query, queryNum] : oflineQueries){
            auto [m, x] = query;
            while(index < n and nums[index] <= m){
                trie.insert(nums[index++]);
            }
            if(index) ans[queryNum] = trie.query(x);
        }

        return ans;

    }
};