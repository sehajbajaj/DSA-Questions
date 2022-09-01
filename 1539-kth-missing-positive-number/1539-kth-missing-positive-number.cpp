class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(auto num : arr){
            if(num <= k){
                k++;
            }
        }
        return k;
    }
};