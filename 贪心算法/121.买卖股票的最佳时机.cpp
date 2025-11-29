#include<LeetCodeStructs.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0],res = 0;
        for(const int& p : prices){
            res = max(p - m,res);
            m = min(m,p);
        }
        return res;
    }
};