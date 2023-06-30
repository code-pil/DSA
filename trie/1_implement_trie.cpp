struct node{
    node* links[26];
    bool flag = false;

    bool containKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, node *Node){
        links[ch-'a'] = Node;
    }

    node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
    node* root;
    Trie() {  
        root = new node();
    }
    
    void insert(string word) {
        node* Node = root;
        for(int i=0;i<word.size();i++){
            if(!Node->containKey(word[i])){
                Node->put(word[i], new node());
            }
            Node = Node->get(word[i]);
        }
        Node->setEnd();
    }
    
    bool search(string word) {
        node* Node = root;
        for(int i=0;i<word.size();i++){
            if(!Node->containKey(word[i])){
                return false;
            }
            Node = Node->get(word[i]);
        }
        return Node->isEnd();
    }
    
    bool startsWith(string prefix) {
        node* Node = root;
        for(int i=0;i<prefix.size();i++){
            if(!Node->containKey(prefix[i])){
                return false;
            }
            Node = Node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */