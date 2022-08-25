### Using Sliding window approach
​
*Identification Step: array, subarray, k (window-size)*
The idea is to use sliding window approach.
- CALCULATION-> Since, we have to calculate the maximum in every window, we can do that by mx = max(mx, a[j]) but there will be a problem when we will slide the window. What if the element to be removed is itself a maximum element of some window, after removing it, we again have to calculate the maximum element in new window but how can we do that because max element for the current window can occur before the jth element as well. So in order to solve this issue, we can store all the elements in a list when encountered.
- EG: 5 1 3 2, 5 has to be removed and jth element is 2 now which is definitely not the max element in the current window(1, 3, 2). How will we keep track of 3 here? By using the list maximum element of a window will always be at the front.
- Also keep in mind that element before j are if smaller than j then they can  never be the answer of subsequent windows and hence needed to popped out of the list.
- J-i+1 < k, j++;
- If the window is found
- ANS-> push the front element in the vector as it will be the answer for current window.
- SLIDE -> While sliding, keep in mind that if the element to be removed is the maximum element of previous window then it has to be popped out of the list as well.
​
#### **TC-> O(N) and SC-> O(N)**
​
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
​
### USING DEQUE AND HEAPS
​
##### **1 HEAP**
##### TC -> O(nlogn)
##### SC -> O(N)