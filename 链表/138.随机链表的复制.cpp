#include<LeetCodeStructs.h>
class Solution {
    public:
        Node* copyRandomList(Node * head){
            //复合二元关系
            unordered_map<Node*,Node*> um;
            Node *p = head;
            while(p){
                um[p] = new Node(p->val);
                p = p->next;
            }
            p = head;
            while(p){
                um[p]->next = um[p->next];
                um[p]->random = um[p->random];
                p = p->next;
            }
            return um[head];
        }

};

// Node* copyRandomList(Node* head) {
//     unordered_map<Node*,int> um;
//     Node* cArray[1000];
//     Node *dummyHead = new Node(0);
//     Node *p = head;
//     Node *cP = dummyHead;
//     int index = 0;
//     um[nullptr] = -1;
//     while(p){
//         um[p] = index;
//         cP->next = new Node(p->val);
//         cArray[index] = cP->next;
//         cP = cP->next;
//         p = p->next;
//         index++;
//     }
//     cP->next = nullptr;
//     p = head;
//     cP = dummyHead->next;
//     while(p){
//         index = um[p->random];
//         cP->random = index >= 0 ? cArray[index] : nullptr;
//         p = p->next;
//         cP = cP->next;
//     }
//     return dummyHead->next;
// }

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
