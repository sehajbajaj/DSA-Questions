class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> pairArray;
        
        for(int i = 0; i < profits.size(); i++){
            pairArray.push_back({capital[i], profits[i]});
        }
        sort(pairArray.begin(), pairArray.end());
        
        priority_queue<int> maxHeap;
        
        int i = 0;
        while(i < pairArray.size() and k){
            if(w >= pairArray[i].first){
                maxHeap.push(pairArray[i++].second);
            }else{
                if(maxHeap.empty()){
                    return w;
                }
                
                w += maxHeap.top();
                maxHeap.pop();
                k--;
            }
        }
        
        while(k-- and !maxHeap.empty()){
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};