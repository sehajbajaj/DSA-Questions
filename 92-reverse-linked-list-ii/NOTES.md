### Using curr, prev, nn pointers with last and newEnd pointers.
​
- Since, we are given a range of nodes and only those nodes have to be reversed.
- We just need to extend the reversal algorithm.
- Initially, curr is at head and prev is at NULL.
- Till curr does not reach the left node, keep updating the prev and curr pointers to curr and curr->next respectively.
- After this take two extra pointers say last = prev and newEnd = curr. these pointers iwll help us connect the new links required later on.
- Reverse the linked list using the reverse algorithm till i < right-left+1. this condition makes sure that we reverse only the nodes in the range [left, right). We observe that right pointer is still needed to be connected to the correct node and this is where the last and newEnd pointers come to the rescue.
- Connect the last pointer's next to prev if last is not NULL and newEnd pointer's next to curr. This ensures that proper and correct connections are made.
- Else return prev.
​
### TC -> O(N) and SC -> O(1)
​