class Solution {
public:
    
    void solve(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> &subsetsTillNow){
        if(index >= nums.size()){
            ans.push_back(subsetsTillNow);
            return;
        }
        
        subsetsTillNow.push_back(nums[index]);
        solve(nums, index + 1, ans, subsetsTillNow);
        subsetsTillNow.pop_back();
        
        while(index + 1 < nums.size() and nums[index] == nums[index + 1]){
            index++;
        }
        solve(nums, index + 1, ans, subsetsTillNow);
        return;
    } 
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subsetsTillNow;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans, subsetsTillNow);
        return ans;
    }
};