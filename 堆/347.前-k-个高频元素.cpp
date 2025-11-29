#include<LeetCodeStructs.h>
typedef pair<int,int> node;
class Solution {
public:
    struct cmp{
        bool operator()(const node& p1,const node& p2){
            return p1.second < p2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> um;
        priority_queue<node,vector<node>,cmp> qp;
        for(const int& num : nums){
            um[num]++;
        }
        for(const node& kv : um){
            qp.push(kv);
        }
        for(int i = 0; i < k; i++){
            res.push_back(qp.top().first);
            qp.pop();
        }
        return res;
    }
};