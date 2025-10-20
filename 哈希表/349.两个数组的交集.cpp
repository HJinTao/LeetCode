#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> hash(1001,0);
        vector<int> res;
        for(int num : nums1){
            if(hash[num] == 0){
                hash[num] = 1;
            }
        }
        for(int num : nums2){
            hash[num] -= 1;
            if(hash[num] == 0){
                res.push_back(num);
            }
        }
        return res;
    }
};