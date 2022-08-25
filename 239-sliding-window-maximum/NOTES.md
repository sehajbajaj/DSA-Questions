### Using Sliding window approach

*Identification Step: array, subarray, k (window-size)* 
The idea is to use sliding window approach. 
- CALCULATION-> Since, we have to calculate the maximum in every window, we can do that by mx = max(mx, a[j]) but there will be a problem when we will slide the window. What if the element to be removed is itself a maximum element of some window, after removing it, we again have to calculate the maximum element in new window but how can we do that because max element for the current window can occur before the jth element as well. So in order to solve this issue, we can store all the elements in a list when encountered. 
	- EG: 5 1 3 2, 5 has to be removed and jth element is 2 now which is definitely not the max element in the current window(1, 3, 2). How will we keep track of 3 here? By using the list maximum element of a window will always be at the front.
	- Also keep in mind that element before j are if smaller than j then they can  never be the answer of subsequent windows and hence needed to popped out of the list.
- J-i+1 < k, j++;
- If the window is found
	- ANS-> push the front element in the vector as it will be the answer for current window.
	- SLIDE -> While sliding, keep in mind that if the element to be removed is the maximum element of previous window then it has to be popped out of the list as well.

#### **TC-> O(N) and SC-> O(N)**

```c++
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
```

### USING DEQUE AND HEAPS

##### **1 HEAP**
##### TC -> O(nlogn)
##### SC -> O(N)

   ```c++
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq; // pair for storing index
        vector<int> ans;
        int i=0,j=0;
        while(j<nums.size())
        {
            pq.push({nums[j],j});   // push every element into heap
            if(j-i+1>=k)      // if condition is met
            {
                
                // while the topmost element is not present in k elements pop them and move forward
                while(pq.top().second<=j-k)      
                {
                    pq.pop();
                    i++;
                }
                ans.push_back(pq.top().first);  // push the top element which is inside the window
            }
            j++;
        }
        return ans;
    }
```

##### **2 HEAPS**

##### TC -> O(klogk)+O((n-k)logk) => O(nlogn)
##### SC -> O(2N)

   ```c++
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Using 2 Heaps
        priority_queue<int> maxH, max2H;
        vector<int> ans;
        
        for(int i = 0; i < k; i++){
            maxH.push(nums[i]);
        }
        ans.push_back(maxH.top());
        
        //Remaining K elements
        for(int i = k; i < nums.size(); i++){
            max2H.push(nums[i-k]);
            maxH.push(nums[i]);
            
            while(maxH.top() == max2H.top() and !maxH.empty() and !max2H.empty()){
                maxH.pop();
                max2H.pop();
            }
            ans.push_back(maxH.top());
        }
        return ans;
    }
```

##### **DEQUE**

```c++
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq(k);
        vector<int> v;
        int n = nums.size();

      for (int i = 0; i < k; i++) {
        while (!dq.empty() and nums[i] >= nums[dq.back()]) {
          dq.pop_back();
        }
        dq.push_back(i);
      }

      for (int i = k; i < n; i++) {
        v.push_back(nums[dq.front()]);
        while (!dq.empty() and dq.front() <= i - k) {
          dq.pop_front();
        }
        while (!dq.empty() and nums[i] >= nums[dq.back()]) {
          dq.pop_back();
        }
        dq.push_back(i);
      }
      v.push_back(nums[dq.front()]);
      return v;
        }
```

```c++
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
```
