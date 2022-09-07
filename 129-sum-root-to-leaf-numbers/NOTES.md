### DFS
​
- We need to take a node and convert it into a digit.
- Remember converting string to integer? Apply the same formula here.
- digit = digit x 10 + root's value.
- If the node is 4, digit initially is 0 now it becomes 0 x 4 = 4 and next node is 9 so now the digit becomes 4 x 10 + 9 = 49 which is exactly what we want.
- Also keep checking that if we reach a leaf node, we have the number to add to sum. We won't make any further calls here and simply add the number formed to the sum and return after backtracking.
- If it's not a leaf node, make calls to left and right child. Backtrack the number => digit / 10.
​
### TC - O(N) and SC -> O(H)