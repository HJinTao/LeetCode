/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
// #include<bits/stdc++.h>
// using namespace std;
// @lc code=start
struct Node{
    int val;
    Node* next;
    Node(int val) : val(val),next(nullptr){}
};
typedef Node* Link;

class MyLinkedList {
public:
    Link head;
    Link sentinel;
    MyLinkedList(int val = 0){
        head = nullptr;
        sentinel = new Node(0); 
        sentinel->next = head;
    }
    int get(int index) {
        int i = 0;
        Node* p = sentinel->next;
        while(i < index && p){
            p = p->next;
            i++;
        }
        return p ? p->val : -1;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(sentinel->val,val);
    }
    
    void addAtIndex(int index, int val) {
        int i = -1;
        Node* p = sentinel;
        while(i < index - 1 && p){
            p = p->next;
            i++;
        }
        if(!p){
            return;
        }
        else{
            Node* addNode = new Node(val);
            addNode->next = p->next;
            p->next = addNode;
            sentinel->val++;
        }
        
    }
    
    void deleteAtIndex(int index) {
        int i = -1;
        Node* p = sentinel;
        while(i < index - 1 && p->next){
            i++;
            p = p->next;
        }
        if(!p->next){
            return;
        }
        else{
            Node* abandonNode = p->next;
            p->next = abandonNode->next;
            delete abandonNode;
            sentinel->val--;
        }
    }

};

// int main(){
//     MyLinkedList Link = MyLinkedList();
//     Link.addAtHead(1);
//     Link.addAtTail(3);
//     Link.addAtIndex(1,2);
//     cout << Link.get(1) << endl;
//     Link.deleteAtIndex(0);
//     cout << Link.get(0) << endl;
// }
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

