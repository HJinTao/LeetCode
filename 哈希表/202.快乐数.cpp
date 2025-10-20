#include<LeetCodeStructs.h>
class Solution {
public:
    int bitSquareSum(int n){
        int sum = 0;
        while(n){
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = bitSquareSum(n);
        while(slow != fast){
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }
        return slow == 1;
    }

};
// bool isHappy(int n) {
//     vector<int> hash(730 + 1,0);
//     while(n != 1){
//         n = bitSquareSum(n);
//         if(hash[n] == 1){
//             return false;
//         }
//         hash[n] = 1;
//     }
//     return true;
// }