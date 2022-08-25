class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        list<int> l;
        
        int i = 0, j = 0;
        while(j < nums.size()){
            //1. Calculation
            while(l.size()>0 and l.back()<nums[j]){
                l.pop_back();
            }
            l.push_back(nums[j]);
            
            //2. Finding teh appropriate window of size k
            if(j-i+1 < k){
                j++;
            }
            //3. Window Found
            else if(j-i+1 == k){
                //4. Calculate ans which will always be at front of the list
                v.push_back(l.front());
                
                //5. Slide the window
                if(l.front() == nums[i]){
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
        return v;
    }
};