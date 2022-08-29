class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        int index = 0;
        
        //Case 1. -> No overlapping intervals befor merging
        while(index < n and intervals[index][1] < newInterval[0]){
            ans.push_back(intervals[index]);
            index++;
        }
        
        //Case 2. Merging of new interval
        while(index < n and newInterval[1] >= intervals[index][0]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        ans.push_back(newInterval);
        
        //Case3. No overlapping after merging
        while(index < n){
            ans.push_back(intervals[index]);
            index++;
        }
        return ans;
    }
};