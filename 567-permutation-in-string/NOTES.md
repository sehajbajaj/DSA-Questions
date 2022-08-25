### Identification
​
- Strings, substrings
- k = s1's length
​
**Fixed sized window**
1. Put the characters of s1 in map 1.
2. Iterate over s2.
3. Insert current element in map 2.
4. **Condition1: Window not found**- if window size is less than s1's length, increase the window size
5. **Condition2: Window found**- window size is equal to s1's length
6. Ans - if both maps are identical
7. Slide, if btoth maps aren't it=dentical.
​
### TC-> O(N) and SC -> O(N)
​
​