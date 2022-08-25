#### This problem is a variant of the problem Longest Substring without repeating characters. We will use a similar sliding-window technique to solve this problem.
​
• Consider each substring as a sliding window.

• Start with a sliding window of size 1 (windowStart=0, windowEnd=0).

• Initialize a HashMap that stores the character count for each character in the current window.

• Iterate over the string and add one letter at a time to the window.

• We will also keep track of the letter that repeats the maximum number of times in the current window. Let’s call it maxRepeatLetterCount.

• In each iteration, we know that we have a window with one letter repeating maxRepeatLetterCount times. Since we only have k replacements allowed, we should keep aside the letter that repeats the most number of times and replace the remaining letters.

  o If the remaining letters in the window are less than or equal to k then we can replace them all.
  
  o Otherwise, we need to shrink the window as we are not allowed to replace more than k letters.
  
### **TC -> O(N) and SC -> O(N)**
​
