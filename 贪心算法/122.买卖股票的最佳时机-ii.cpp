#include<LeetCodeStructs.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int m = prices[0],res = 0;
        // for(const int& p : prices){
        //     if(p > m){
        //         res += p - m;
        //         m = p;
        //     }
        //     else{
        //         m = min(p,m);
        //     }
        // }
        // return res;
        //更聪明的解法:把利润分为每天的利润
        int res = 0,n = prices.size();
        for(int i = 1; i < n;i++){
            int profit = prices[i] - prices[i - 1];
            if(profit > 0){
                res += profit;
            }
        }
        return res;
    }
};