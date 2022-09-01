### Using odd, even and newLast pointers.
​
- Assign odd to head and even to head's next.
- Assign newLast to head's next. This pointer helps us to give new tail for the Linked list.
- While odd's next and even's next is not null
- Keep updating the pointers so that all odds are together and all evens are together.
- We observe that odd and even nodes are not connected together. So, connect the last odd node to the fist even node with help of the newLast pointer which was assigned to the first even node.
​
### TC -> O(N) and SC -> O(1)
​