class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        vector<int> ans;
        while(i < nums.size()){
            int correct = nums[i]-1;
            
            if(nums[i] != nums[correct]){
                swap(nums[i], nums[correct]);
            }else{
                i++;
            }
        }
        
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != j+1){
                ans.push_back(j+1);
            }
        }
        return ans;
    }
};