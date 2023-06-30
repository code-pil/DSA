
struct Node{
    Node* link[26];

    bool containKey(char ch){
        return link[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    int n = s.size();
    Node* root = new Node();
    int cnt=1;
    for(int i=0;i<n;i++){
        Node* node = root;
        for(int j=i;j<n;j++){
            if(!node->containKey(s[j])){
                node->put(s[j], new Node());
                cnt++;
            }
            node = node->get(s[j]);
        }
    }
    return cnt;
}