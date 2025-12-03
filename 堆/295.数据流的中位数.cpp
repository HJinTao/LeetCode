#include<LeetCodeStructs.h>
class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;  // 存储size/2+size%2个元素
    priority_queue<int,vector<int>,less<int>> maxHeap;//存储size/2个元素
    MedianFinder() {

    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());  minHeap.pop();
        while(maxHeap.size() > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() != maxHeap.size()){
            return (double)minHeap.top();
        }
        else{
            return ((double)minHeap.top() + (double) maxHeap.top()) / 2;
        }
    }
};