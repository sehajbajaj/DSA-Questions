### Make use of 2 LL questions
​
- Find the mid of the Linked List.
- Reverse the second half and you get the secondHead.
- Now, comes the main part
- While both of the heads are not NULL
- Check if the value of the nodes is not equal, break the while loop else just keep moving the heads forward.
- Check if either of head reaches the end of the LinkedList, return true as its a palindrome
- Return false.
​
### TC -> O(N) and SC -> O(1)
​