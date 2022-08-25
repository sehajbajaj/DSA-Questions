class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int trappedWater = 0;
        int leftMaxHeight = 0, rightMaxHeight = 0;
        
        while(left <= right){
            if(height[left] < height[right]){
                if(height[left] > leftMaxHeight){
                    leftMaxHeight = height[left];
                }else{
                    trappedWater += leftMaxHeight - height[left];
                }
                left++;
            }else{
                if(height[right] > rightMaxHeight){
                    rightMaxHeight = height[right];
                }else{
                    trappedWater += rightMaxHeight - height[right];
                }
                right--;
            }
        }
        return trappedWater;
    }
};