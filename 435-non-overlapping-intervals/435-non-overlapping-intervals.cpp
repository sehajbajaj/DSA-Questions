class Solution {
public:
    
    static bool cmp(const vector<int>&v1, const vector<int>&v2){
        if(v1[1] == v2[1]) return v1[0] < v2[0];
        
        return v1[1] < v2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int eraseCount = 0;
        
        sort(intervals.begin(), intervals.end(), cmp);
        int temp = intervals[0][1];
        for(int it = 1; it < intervals.size(); it++){
            if(intervals[it][0] < temp){
                eraseCount++;
            }else{
                temp = intervals[it][1];
            }
        }
        return eraseCount;
    }
};