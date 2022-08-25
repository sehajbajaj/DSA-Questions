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
​
```c++
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
priority_queue<pair<int,int>>pq; // pair for storing index
vector<int> ans;
int i=0,j=0;
while(j<nums.size())
{
pq.push({nums[j],j});   // push every element into heap
if(j-i+1>=k)      // if condition is met
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