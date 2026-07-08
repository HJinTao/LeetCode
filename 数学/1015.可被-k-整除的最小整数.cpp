#include<LeetCodeStructs.h>
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0){
            return -1;
        }
        int r = 1 % k;
        int m = 1;
        for(; m < k && r != 0; m++){
            r = (10 * r + 1) % k;
        }
        return m;
    }
};