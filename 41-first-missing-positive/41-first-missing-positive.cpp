class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            int correct = (long)nums[i]-1;
            if(nums[i] <= nums.size() and nums[i] > 0 and nums[i] != nums[correct]){
                swap(nums[i], nums[correct]);
            }else{
                i++;
            }
        }
        
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != j+1){
                return j+1;
            }
        }
        return nums.size()+1;
    }
};