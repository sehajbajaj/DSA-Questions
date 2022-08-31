class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        
        while(i < nums.size()){
            int correct = nums[i];
            if(nums[i] < nums.size() and nums[i] != nums[correct]){
                swap(nums[i], nums[correct]);
            }else{
                i++;
            }
        }
        
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != j){
                return j;
            }
        }
        return nums.size();
    }
};