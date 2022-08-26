### Using fast and slow pointers
​
- Floyd's Cycle detection Algorithm - Tortoise and Hare Algo
- Initialise slow and fast as head.
- While fast and fast's next is not null
- Move fast forward by 2 steps and slow by 1 step
- Check if both become equal, means linked list has a cycle.
- Return false if no cycle detected.
​
### TC -> O(N) and SC -> O(1)