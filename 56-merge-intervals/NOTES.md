### Using Greedy Approach
​
- Sort the intervals.
- We basically have to compare the start time of previous interval with the end time of it's next interval. To do so:
- Store the 1st interval in a vector, say temp.
- Traverse over the interval array and compare every interval's start time with stored interval's end time.
- If the start time of current interval is less than or equal to stored interval's end time then update the stored interval's end time to the maximum of current interval's or it's own end time.
- Else if the start time is more than end time, we have calculated one correct interval. Push the stored interval in the answer vector and update temp vector.
​
### TC -> O(NlogN) + O(N) and SC -> O(N)
​