/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> map;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        queue<Node*> q;
        q.push(node);


        map[node] = new Node(node->val);
        auto ans = map[node];

        while(!q.empty()){
            node = q.front();
            q.pop();

            for(auto &neighbor : node->neighbors){
                if(!map.count(neighbor)){
                    map[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                map[node]->neighbors.push_back(map[neighbor]);
            }
        }
        return ans;
    }
};