### Using Greedy Approach
​
- Sort the intervals array in the increasing order of end points.
- Store the end point of the 1st interval in a variable, say temp.
- While traversing from the 2nd interval, keep comparing the value of temp with the start point of current interval.
- If temp > start point of current interval, we have an overlapping. Increment cnt.
- Else, update temp to be the end point of current interval.
​
### TC -> O(NlogN) and SC -> O(1)
​