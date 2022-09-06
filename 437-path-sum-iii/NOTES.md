### Brute Force
​
- Focusing on the line, “The path does not need to start or end at the root or a leaf, …“, we can conclude that we can start from any point.
- In other words, we can restart our counting of the path sum from anywhere we like. We can either:
- start the sum counting from 0 – restarting
- continue the sum from what the parent gave us
- Let’s formalize this. Since we want to search for a path in a tree, we are going to use depth first search (DFS). It takes dfs(root, current_sum, target_sum, reset, resetted)
- where root is the node we are at currently, current_sum is the current path's sum, target_sum is the given sum, reset is a bool variable that tells us if we have to reset the current_sum or not, resetted is a set that helps in optimzing the code to avoid recomputations.
- Keep calculating the count of paths from the parent node and count of paths when current_sum is reset. If the resent request is sent and the current node is already present in the set, it means we are recomputing the sum for that node, to prevent this return 0. Else simply add the current node to the set and continue with the computations
​
### TC - O(N2) and SC - O(N)
​
### Optimized
​
- The idea is to use cummulative sum or prefix sum approach.
- While calculating sum(i, j) for an array, teh answer can be calculated easily by storing cumulative sums in cums array. ans = cums[j+1] - cums[i].
- Using the same idea here, we can replace the logic of resetting the csum.
- But since, in a tree we don't have random access facility so we need a data structure to store all the values visited. Use hashmap for this.
- Before calling for left and right sub trees, we will set some future goals **goal = csum + targetSum** for our recursion to meet **mark[goal] += 1**.
- We are baiting the future dfs calls to find us the goal. If any of the calls find the goal, we will happily increment the answer by the value of csum stored in the map **ans += mark[csum]**.
- At some point in future when our csum becomes equal to goal, we have already marked it as 1 or set. We should also be able to remove this goal after the calls are made and we have updated our ans.
​
### TC - O(N) and SC - O(N)
​