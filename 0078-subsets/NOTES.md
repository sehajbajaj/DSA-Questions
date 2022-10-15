#### Using Recursion
​
- We can start from anywhere, first element or last element.
- Here, by starting from the first element, the index i is initially 0.
- We have 2 options to either take the element at the ith index in the vector or leave it. We have to compute answers for both the cases.
- 1st case - Leave it.
- 2nd case - Take it and push it into the vector
- Repeat the above steps till the ith index doesn't become more than or equal to the length of the given nums array which is the base condition.
​
#### TC - O(2^n) and SC - O(n)