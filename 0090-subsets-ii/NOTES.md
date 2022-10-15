#### Using recursion/backtracking
​
- We have two options. 1, Take the current element 2. Leave the current element.
- We also have to ignore the repeated outputs.
- Keep inserting the current element into the vector. Pop them out after computing their answer.
- To ignore the repeated elements, check if the current element is same as the next element then simply ignore the current element and compute the next element instead as the answers for both is anyhow going to be the same which is to be prevented.
​
​