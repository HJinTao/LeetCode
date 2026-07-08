#include<LeetCodeStructs.h>
class Solution {
public:

    string getPermutation(int n, int k){
        vector<int> fact(n, 1);
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        for(int i = 2; i < n; i++){
            fact[i] = fact[i - 1] * i;
        }

        string res = "";
        k -= 1;
        for(int i = n - 1; i >= 0; i--){
            int coef = k / fact[i];
            res.push_back(nums[coef] + '0');
            nums.erase(nums.begin() + coef);
            k %= fact[i];
        }

        return res;
    }


    string getPermutation_(int n, int k) {
        string res;
        string path;
        vector<int> used(n + 1, false);
        function<void()> dfs = [&]() -> void{
            if(path.size() == n){
                if(--k == 0){
                    res = path;
                    return;
                }
            }
            else{
                for(int i = 1; i <= n && k != 0; i++){
                    if(!used[i]){
                        used[i] = true;
                        path.push_back(i + '0');
                        dfs();
                        path.pop_back();
                        used[i] = false;
                    }
                }
            }
        };
        dfs();
        return res;
    }
};