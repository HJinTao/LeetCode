#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 1 || nums.empty()){
            return nums;
        }
        int mid = nums.size() / 2;
        vector<int> l(nums.begin(),nums.begin() + mid);
        vector<int> r(nums.begin() + mid,nums.end());
        l = sortArray(l);
        r = sortArray(r);
        vector<int> res;
        int p1 = 0,p2 = 0;
        while(p1 < l.size() && p2 < r.size()){
            if(l[p1] <= r[p2]){
                res.push_back(l[p1++]);
            }
            else{
                res.push_back(r[p2++]);
            }
        }
        if(p1 < l.size()){
            while(p1 < l.size()){
                res.push_back(l[p1++]);
            }
        }
        else{
            while(p2 < r.size()){
                res.push_back(r[p2++]);
            }
        }
        return res;
    }

    void sortArrayIterator(int left,int right,vector<int>& nums){
        
    }
};