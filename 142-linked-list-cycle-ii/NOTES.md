### Using fast and slow pointers

- Initialize both slow and fast as head
- Similar to cycle detection, while fast or fast->next is not null
	- Move fast by 2 steps and slow by 1 step.
	- If both becom eequal, break out of the while loop.
- After breaking out of while loop, check if there's not a cycle, return null.
- If there is one, take slow back to head and now till both slow and fast again do not become equal keep moving them forward by 1 step.
- Return slow or fast as both will be equal if a cycle exists.

### TC -> O(N) and SC ->  O(1)
