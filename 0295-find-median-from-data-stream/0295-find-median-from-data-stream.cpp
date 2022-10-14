class MedianFinder {
                
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
        }else if(minHeap.empty()){
            if(maxHeap.top() > num){
                int x = maxHeap.top();
                maxHeap.pop();
                minHeap.push(x);
                maxHeap.push(num);
            }else{
                minHeap.push(num);
            }
        }else{
            if(maxHeap.size() > minHeap.size()){
                if(maxHeap.top() > num){
                int x = maxHeap.top();
                maxHeap.pop();
                minHeap.push(x);
                maxHeap.push(num);
                }else{
                    minHeap.push(num);
                }
            }else{
                if(num <= maxHeap.top()){
                    maxHeap.push(num);
                }else{
                    minHeap.push(num);
                    int x = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(x);
                }
            }
        }       
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */