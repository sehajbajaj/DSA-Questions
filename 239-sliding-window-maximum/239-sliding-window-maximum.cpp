class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> result;
        deque<int> dq;
        
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            while (dq.empty() != true && dq.front() < nums[windowEnd]) {
                dq.pop_front();
            }
            dq.push_front(nums[windowEnd]);
            if (windowEnd >= k - 1) {
                result.push_back(dq.back());
                if (nums[windowStart] == dq.back()) dq.pop_back();
                windowStart++;
            }
        }
        return result;
    }
};