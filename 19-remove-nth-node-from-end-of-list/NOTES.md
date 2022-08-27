### Using fast and slow pointers
​
- fast and slow is initially at head.
- move fast forward by 1 step n-1 times.
- Check if fast becomes Null, return slow->next
- While fast->next != null, move both the pointers by 1 step each.
- Update the slow's next pointer.
- Return head.
​
### TC -> O(N) and SC -> O(1)
​