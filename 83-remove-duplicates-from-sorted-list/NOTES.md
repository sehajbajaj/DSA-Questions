### Using fast and slow pointers
- slow = head
- fast = head->next
- While the slow->next is not null
- if the value of both slow and fast is same, connect the slow's nect to fast's next in order to remove the dupes found. Also update fast.
- if not same values, then simply move both of them forward.
​
### TC -> O(N) and SC -> O(1)