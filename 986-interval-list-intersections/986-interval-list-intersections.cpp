class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int ptr1 = 0;
        int ptr2 = 0;
        vector<vector<int>> ans;
        
        while(ptr1 < firstList.size() and ptr2 < secondList.size()){
            // Find the start and end points.
            int start = max(firstList[ptr1][0], secondList[ptr2][0]);
            int end = min(firstList[ptr1][1], secondList[ptr2][1]);
            
            // Valid intersection
            if(start <= end){
                ans.push_back({start, end});
            }
            
            // Update ptrs
            if(firstList[ptr1][1] < secondList[ptr2][1]){
                ptr1++;
            }else{
                ptr2++;
            }
        }
        return ans;
    }
};