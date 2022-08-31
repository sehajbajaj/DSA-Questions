### Using Cyclic Sort
​
- Traverse over the array and keep track of the correct position for every element if the array were to be sorted.
- Eg: nums = [6,4,2,3,5,7,0,1], after sorting this would be => [0, 1, 2, 3, 4, 5, 6, 7]. We notice that the correct position of every element is the same index as their value. Correct position for 0 is 0th index, 1 is 1st index, 2 is 2nd index and so on...
- If the element is at it's correct position, continue.
- Else, swap the element at the correct position at the current position.
- Traverse the array again, and check if the element at current position is equal to the index or not.
- If its equal, its not missing
- If it's not equal it is the missing number.
- EG: nums = [9,6,4,2,3,5,7,0,1] => 9 is the missing number as after sorteing we'll observe that only 9 is the one which is not at the correct position. So return 9.
​
### TC -> O(N) and SC -> O(1)
​