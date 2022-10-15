class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        
        for(auto ele : nums){
            mp[ele]++;
        }
        solve(ans, temp, mp, 0, nums.size());
        return ans;
    }
    
    void solve(vector<vector<int>> &ans, vector<int> temp, unordered_map<int, int> &mp, int index, int n){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        
        for(auto it : mp){
            int key = it.first;
            int val = it.second;
            
            if(val == 0){
                continue;
            }
            
            temp.push_back(key);
            mp[key]--;
            
            solve(ans, temp, mp, index + 1, n);
            
            temp.pop_back();
            mp[key]++;
        }
    }
};