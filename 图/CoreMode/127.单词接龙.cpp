#include<LeetCodeStructs.h>
class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        if(find(wl.begin(),wl.end(),ew) == wl.end()){
            return 0;
        }
        unordered_map<string,vector<string>> um;
        int len = bw.size();
        for(int i = 0; i < len; i++){
            string tmp = bw;
            tmp[i] = '*';
            um[bw].push_back(tmp);
            um[tmp].push_back(bw);
        }
        for(const string& w : wl){
            for(int i = 0; i < len; i++){
                string tmp = w;
                tmp[i] = '*';
                um[w].push_back(tmp);
                um[tmp].push_back(w);
            }            
        }
        queue<string> qstart,qend;
        unordered_map<string,bool> v1,v2;
        int cnt1 = 1,cnt2 = 1;   //cnt代表经过的顶点数,与q的初始状态相对应,所以是1
        qstart.push(bw);
        qend.push(ew);
        v1[bw] = true;
        v2[ew] = true;


        while(!qstart.empty() && !qend.empty()){
            int size = qstart.size();
            cnt1++;
            while(size--){
                string x = qstart.front();  qstart.pop();
                if(v2.find(x) != v2.end()){
                    return (cnt1 + cnt2) / 2;
                }
                for(const string& y : um[x]){
                    if(v1.find(y) == v1.end()){
                        qstart.push(y);
                        v1[y] = true;
                    }
                }
            }
            size = qend.size();
            cnt2++;
            while(size--){
                string x = qend.front();  qend.pop();
                if(v1.find(x) != v1.end()){
                    return (cnt1 + cnt2) / 2;
                }
                for(const string& y : um[x]){
                    if(v2.find(y) == v2.end()){
                        qend.push(y);
                        v2[y] = true;
                    }
                }
            }
        }
        return 0;
    }
};