### We already know that intervals are sorted and do not overlap, they will only be distirbed on the merging of new interval.
​
**So, we have bascially extend the range of the newInterval**
​
- Case 1 is when there are no overlapping intervals as of now in the beginning. So we just keep pushing the intervals in the ans after comparing the end[i] of current interval with start[i] of newInterval.
- Case 2 is when overlap occurs due to newInterval and now we have to extend the ranges.
- Update the newInterval's start and end in order to insert the newInterval.
- Push the newInterval formed to the ans.
- Case 3 is when merging is done and no more overlap occurs so we simply push the current interval again to the ans.
​
### TC -> O(N) as we are traversing over the array once and SC -> O(N) to store the answer.
​
### Another concise way to do is as follows:
​
```c++
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
vector<vector<int>> ans;
for(auto &it : intervals) {
if(it[1] >= newInterval[0] and it[0] <= newInterval[1]) {
newInterval[0] = min(it[0],newInterval[0]);
newInterval[1] = max(it[1],newInterval[1]);
}
else {
if(it[0] > newInterval[0])
swap(it,newInterval);
ans.push_back(it);
}
}
ans.push_back(newInterval);
return ans;
}
```
​