class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapp;
        
        for(auto str : strs){
            string temp = str;
            sort(str.begin(), str.end());
            mapp[str].push_back(temp);
        }
        
        vector<vector<string>> ans;
        for(auto pairs : mapp){
            ans.push_back(pairs.second);
        }
        
        return ans;
    }
};