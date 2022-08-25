### Identification Step: string, substring, k (window-size) given as pattern’s size
​
The idea is to use sliding window approach+Hashing.
- Calculation Step -> Make a map or unordered map of pattern.
- Check if jth element is a part of map or not, if it is then decrement its frequency.
- Keep a variable count that is the size of the map. If the frequency of any character in the map becomes 0, decrement the count as well.
- Check for the window size < k, increment j
- If found the window
- ANS-> if count == 0, it means we have found 1 anagram as all the characters in pattern map have found a match, hence increment ans.
- SLIDE-> Before sliding, we have to reverse the calculations for the ith character. If its present in the map we’ll increase it’s count because now we are looking for another anagram so that letter has to be put back in the map and if the frequency of any character becomes 1 increment the count as well.
### TC -> O(N) and SC -> O(N)
​
​