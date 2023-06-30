/*
See defination of LRU cache

Leetcode: https://leetcode.com/problems/lru-cache/description/

*/

class LRUCache {
public:

    class node {
    public:
        int val;
        int key;
        node *next;
        node *prev;
        node(int key, int val){
            this->key = key;
            this->val = val;
            next=NULL;
            prev=NULL;
        }
    };

    int cap;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    unordered_map<int,node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node *NEW){
        node *tmp = head->next;
        head->next = NEW;
        NEW->next = tmp;
        tmp->prev = NEW;
        NEW->prev = head;
    }

    void deleteNode(node *delnode){
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }
    
    int get(int key_) {
        if(m.find(key_)!=m.end()){
            node *pronode = m[key_];
            int ans = m[key_]->val;
            m.erase(key_);
            deleteNode(pronode);
            addNode(pronode);
            m[key_]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_)!=m.end()){
            node *existingnode = m[key_];
            m.erase(key_);
            deleteNode(existingnode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key_, value));
        m[key_]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */