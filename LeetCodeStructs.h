#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

struct DSU{
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        rank = vector<int>(n, 1);
    }

    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool isConnected(int x, int y){
        return find(x) == find(y);
    }

    void unite(int x, int y){
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY){
            return;
        }
        else{
            int rx = rank[rootX], ry = rank[rootY];
            if(rx < ry){
                parent[rootX] = rootY;
            }
            else if(rx == ry){
                parent[rootX] = rootY;
                rank[rootY]++;
            }
            else{
                parent[rootY] = rootX;
            }
        }
    }
};
