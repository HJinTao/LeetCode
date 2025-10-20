#include<LeetCodeStructs.h>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int left = 0;
        int right = 0;
        vector<vector<int>> res;
        while(left < intervals.size()){
            while(right < intervals.size() && intervals[right][0] <= intervals[left][1]){
                intervals[left][1] = max(intervals[left][1],intervals[right][1]);
                right++;
            }
            res.push_back(intervals[left]);
            left = right;
        }
        return res;
    }
};