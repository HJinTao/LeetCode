#include<LeetCodeStructs.h>
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        int val = mp[key]->second;
        put(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            ls.erase(mp[key]);
        }
        ls.push_front(make_pair(key,value));
        mp[key] = ls.begin();
        if(ls.size() > cap){
            auto f = ls.back();
            mp.erase(f.first);
            ls.pop_back();
        }
    }


private:
    int cap;
    list<pair<int,int>> ls;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    
};