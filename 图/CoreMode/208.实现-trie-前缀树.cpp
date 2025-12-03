#include<LeetCodeStructs.h>
#define SIZE 26
class Trie {
private:
    struct Node{
        Node* children[SIZE];
        bool isEnd = false;
        Node(){
            for(Node*& child : children){
                child = nullptr;
            }
        }
    };
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char& ch : word){
            if(!cur->children[ch - 'a']){
                cur->children[ch - 'a'] = new Node();
            }
            cur = cur->children[ch - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char &ch : word){
            if(cur->children[ch - 'a']){
                cur = cur->children[ch - 'a'];
            }
            else{
                return false;
            }
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char &ch : prefix){
            if(cur->children[ch - 'a']){
                cur = cur->children[ch - 'a'];
            }
            else{
                return false;
            }
        }
        return true;
    }

};
