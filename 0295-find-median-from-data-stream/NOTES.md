#### Idea is:
​
* if you have [1,2,3,4]. break it down into 2 halves: [1,2] and [3,4].
* using min and max heaps, we can find the min and max of the heap at its top respectively.
* making lower as maxheap and upper as minheap, we get lower.top() = 2 and upper.top() = 3
* while creating these heaps, make sure you push them evenly in both, count helps us there. We readjust the length of both the heaps using count
* for even elements, return lower.top() + upper.top()/ 2. For odd elements, return the extra element from upper