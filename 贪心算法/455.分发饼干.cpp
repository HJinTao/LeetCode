#include<LeetCodeStructs.h>
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int idx = 0,size = g.size();
        for(const int& cookie : s){
            if(idx < size && g[idx] <= cookie){
                idx++;
            }
        }
        return idx;
    }
};