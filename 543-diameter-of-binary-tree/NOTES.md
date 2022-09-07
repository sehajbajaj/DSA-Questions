### DFS
​
- Idea is to calculate the diamaeter while calculating the height of the binary Tree. This helps in reducing the Time Complexity from O(n2) to O(n).
- Base case = if root is null, height will be 0, return 0.
- Make calls on left child and right child.
- Also, keep updating the answer to be max(ans, height of LST + height of RST)
- Return the height => 1 + max(height of LST, height of RST).
​
### TC -> O(N) and SC -> O(H)