class Solution {
public:
    void solve(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> subsetsTillNow){
        //base case
        if(index >= nums.size()){
            ans.push_back(subsetsTillNow);
            return;
        }
        solve(nums, index+1, ans, subsetsTillNow);
        subsetsTillNow.push_back(nums[index]);
        solve(nums, index+1, ans, subsetsTillNow);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subsetsTillNow;
        
        solve(nums, 0, ans, subsetsTillNow);
        return ans;
    }
};