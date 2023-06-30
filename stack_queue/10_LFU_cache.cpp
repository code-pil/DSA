/*

Least Frequntly Used Cache

TUF: https://youtu.be/0PSB9y8ehbk
Leetcode: https://leetcode.com/problems/lfu-cache/description/  

*/


struct Node{
    int key, val, ct;
    Node *next;
    Node *prev;
    Node(int _key, int _val){
        key = _key;
        val = _val;
        ct=1;
    }
};

class List{
public:
    int size;
    Node *head;
    Node *tail;
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;
        size = 0;
    }

    void addFront(Node *node){
        Node *tmp = head->next;
        head->next = node;
        node->next = tmp;
        tmp->prev = node;
        node->prev = head;
        size++;
    }

    void removeNode(Node *delnode){
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
        size--;
    }
};

class LFUCache {
public:

    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:

    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq=0;
        curSize=0;
    }

    void updateFreqList(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->ct]->removeNode(node);
        if(node->ct == minFreq and freqListMap[node->ct]->size == 0){
            minFreq++;
        }
        
        List *nextHigherList = new List();
        if(freqListMap.find(node->ct+1) != freqListMap.end()){
            nextHigherList = freqListMap[node->ct+1];
        }
        node->ct += 1;
        nextHigherList->addFront(node);
        freqListMap[node->ct] = nextHigherList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node *node = keyNode[key];
            int val = node->val;
            updateFreqList(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
        }
        else{
            if(curSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */