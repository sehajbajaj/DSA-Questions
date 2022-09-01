### Using prev, curr and nn pointer.
​
- Take a pointer say, prev = null initially.
- Put curr pointer to head and also nn pointer.
- Traverse over the Linked List and update the pointers accordingly.
- nn = curr->next
- curr->next = prev
- prev = curr
- curr = nn
- Return prev
​
### TC -> O(N) and SC -> O(1)
​