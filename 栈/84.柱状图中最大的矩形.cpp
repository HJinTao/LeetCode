#include<LeetCodeStructs.h>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> s(heights.size(),1);
        stack<int> lst;
        stack<int> rst;
        for(int i = 0; i < heights.size(); i++){
            while(!rst.empty() && heights[rst.top()] > heights[i]){
                s[rst.top()] += i - rst.top() - 1;
                rst.pop();
            }
            rst.push(i);
        }
        while(!rst.empty()){
            s[rst.top()] += heights.size() - 1 - rst.top();
            rst.pop();
        }

        for(int i = heights.size() - 1;i >= 0; i--){
            while(!lst.empty() && heights[lst.top()] > heights[i]){
                s[lst.top()] += lst.top() - i - 1;
                lst.pop();
            }
            lst.push(i);
        }
        while(!lst.empty()){
            s[lst.top()] += lst.top();
            lst.pop();
        }

        int res = INT_MIN;
        for(int i = 0; i < s.size(); i++){
            s[i] *= heights[i];
            res = max(s[i],res);
        }
        return res;
    }
};
