### Using middle and reverse functions.
​
- We observe that last node -> second node, second node -> third node and third node -> last node.
- First find the middle of LL and reverse the second half.
- Now traverse on both and while both heads are not null
- Keep swapping the pointers as follows:
- store the h1's next node into temp node.
- Assign h2 to h1's next (last node becomes the second node)
- Move head to temp.
- Similarly, store h2's next to temp node.
- Assign h1 to h2's next (second node become the third node)
- Move head to temp.
- Repeat the above steps while both heads are not null.
​
### TC -> O(N) and SC -> O(1)
​