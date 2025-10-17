#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q(k);
        vector<int> res(n - k + 1);
        int index;
        for(int i = 0; i < nums.size(); i++){
            index = i - k + 1;
            if(index < 0){
                while(!q.empty() && nums[q.back()] < nums[i]){
                    q.pop_back();
                }
                q.push_back(i);
            }
            else{
                while(!q.empty() && (nums[q.back()] < nums[i] || q.back() < index)){
                    q.pop_back();
                }
                q.push_back(i);

                while(q.front() < index){
                    q.pop_front();
                }
                res[index] = nums[q.front()];
            }
        }
        return res;
    }
};


