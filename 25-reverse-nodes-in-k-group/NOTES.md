### Extending the reversal also + recursion
​
- Take a pointer, say temp = head initially.
- Run a loop from i = 0 till k and keep checking if temp reaches null return head else update temp = temp->next. This way we can easily form a group of k-nodes.
- Run the reversal algorithm for every k nodes.
- After the 1st group is reversed, for the next group recursion is used.
- head->next = reverse(curr, k)
- At the end, return previous because that is the newHead after reversal.
​
### TC -> O(N) and SC -> O(N/k)