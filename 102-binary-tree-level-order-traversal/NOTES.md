### Using queue
​
- Push the root node in the queue.
- While queue is not empty, repeat the following steps.
- Calculate the size of the queue.
- Run a loop from i = 0 till the size calculated. => ensures that the nodes in the current level are being worked upon.
- Store the node at front and pop it from the queue. Push the node's value to the vector.
- Also push it's left and right nodes to the queue. (nodes in the next level)
​
### TC -> O(N) and SC -> O(N)