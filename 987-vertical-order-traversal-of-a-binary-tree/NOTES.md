### BFS
​
- **The idea is to use the logic of horizontal distances and levels**
- Keep in mind that if overlap occurs, print the smaller element first. So to ensure this, we might need a data structure.
- Data Structures:
- map< int, map < int, multiset< int > > > m;
- We are using map to store the horizontal distances mapped with a map of levels in turn mapped with a multiset of node's value. Why multiset? We can have same node value as well. This will also ensure that the nodes are traversed in a sorted manner so that the edge case of overlap can be satisfied.
- This can also be done using any DFS traversal, here we are using BFS.
- Push the root in the queue along with its horizontal distance, level and it's value. (hd = 0, level = 0)
- Process the element at front of the queue by adding it into the map.
- Now to process the left child, hd - 1 and level + 1 will be done.
- And to process the right child, hd + 1 and level + 1 is done.
- Traverse over the whole map and push the elements in the answer vector.
​
### TC - O(NlogN) since we are using multiset and SC - O(N) for all the extra data structures used like map and queue.