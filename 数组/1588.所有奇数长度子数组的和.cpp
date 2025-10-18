#include<LeetCodeStructs.h>
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prePreSum(n);
        prePreSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            arr[i] += arr[i - 1];
            prePreSum[i] = prePreSum[i - 1] + arr[i];
        }
        int res = arr[n - 1];
        for(int i = 3; i <= n; i += 2){
            if(i == n){
                res += arr[n - 1];
            }
            else{
                res += prePreSum[n - 1] - prePreSum[i - 2] - prePreSum[n - 1 - i];
            }
        }
        return res;
    }
};