class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximumSum = INT_MIN;
        int cumulativeSum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            cumulativeSum += nums[i];
            maximumSum = max(maximumSum, cumulativeSum);
            
            if(cumulativeSum < 0){
                cumulativeSum = 0;
            }
        }
        return maximumSum;
    }
};