### Approach
​
**The lists given in reverse order actually is better for us, it helps us as while adding the numbers we start adding the digit at ones place first**
​
- We also need to keep track of carry as well. Let it be initialised as a variable, carry = 0.
- Take a dummy node, put temp = dummy. (it qill help us later for forming a new ll that stores the sum).
- While we have nodes in either of the list or we have a carry, we need to calculate the sum.
- If list1 is not null, add it's node's value to the sum and move the pointer forward.
- If also, the list2 is not null, add it's value and move forward.
- Also add the carry to the sum if any.
- Update carry as sum/10 (carry is always the digits except the last one)
- Make a new node with sum%10 as the value ( to store the sum's digits)
- Update temp pointer, temp->next = new node created and then temp = temp->next.
- And the answer list is formed.
​
### TC -> O(max(M, N)) and SC -> O(max(M,N))+1