#include<LeetCodeStructs.h>
class Solution {
public:

    bool check(int num){
        int x,temp = num;
        while(num > 0){
            x = num % 10;
            num /= 10;
            if(x == 0 || temp % x != 0){
                return false;
            }
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res = {};
        for(int i = left; i <= right; i++){
            if(check(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};