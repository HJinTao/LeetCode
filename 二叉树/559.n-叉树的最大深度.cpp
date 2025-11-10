#include<LeetCodeStructs.h>
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)  return 0;
        int depth = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int curLevelSize = q.size();
            for(int i = 0; i < curLevelSize; i++){
                Node* node = q.front();
                q.pop();
                if(!node->children.empty()){
                    for(Node* n : node->children){
                        q.push(n);
                    }
                }
            }
            depth++;
        }
        return depth;
    }
};