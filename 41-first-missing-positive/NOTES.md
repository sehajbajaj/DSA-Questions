### Using Cyclic sort
​
- Considering the array to be 0-indexed array
- Put all the elements at their correct position. Do keep in mind to check that element should be in the range [1, size].
- Traverse the array again and return the index whose previous index doesn't contain the correct element.
- Eg: [3, 4, -1, 1] => after swapping the elements = [1, -1, 3, 4]. The answer will be index+1 i.e 1+1 = 2.
​
### TC -> O(N) and SC -> O(1)