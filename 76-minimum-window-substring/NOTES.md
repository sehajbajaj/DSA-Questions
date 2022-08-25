#### Identification Step: strings, substring, condition
#### The idea is to use sliding window approach + Hashing. 

WE ARE GIVEN TWO SUBSTRINGS AND T’S CHARACTERS SHOULD BE PRESENT IN S.
WINDOW SIZE ISN’T GIVEN BUT CAN BE CALCULATED BY MAP’S SIZE .
1. To keep track of map’s size maintain a variable count which will be equal to map’s size at any point of time.̥
2. Push all the characters of t in map.
3. Calculation step -> Check if jth character of s is present in the map? If yes, then decrease its frequency and if the frequency becomes 0 then decrease the count as well.
		The above step tells us that we have found one desired character and hence we decrease the frequency and if all the desired no. of times of that character is also found that characters frequency will be 0 and hence count --.
4. If count > 0, it means that we still haven’t found the desired number of desired characters and hence increase the window size.
5. If count == 0 means we have found one candidate window.
	6. ANS-> Calculate answer by ans = min(ans, j-i+1)
	7. Also while count == 0, we will try to optimize the length of the window to as minimum as possible by trying to remove the unnecessary characters by sliding the window.
		8. Check if ith element is not in the map, it means it isn’t the desired character and can be removed simply, shift I forward and calculate another candidate answer again.
		9. If the ith element is in the map, it means it is one of the desired characters and now we will have to reverse the calculations because now we need to find another window with that element in it.
		10. In order to do that increase the character’s frequency in the map and if the frequency becomes more than 0, means desired character condition has to be fulfilled again and hence count++
		11. And if frequency does not become more than 0, it means that particular desired character was extra in s string and can be ignored, So shift I forward and again calculate a candidate answer. 

##### **Optimal:- Analysis: T(C)=O(n) S(C)=O(n)**

```c++
string minWindow(string s, string t) {
       unordered_map<char,int> hash;
        
        //O(n) step
        for(char i: t)
            hash[i] += 1;
        int count = hash.size();
        
        int i=0,j=0;
        pair<int,int> ans; // {starting index, size} to store best result for which we need to do substr only once
        int counter = INT_MAX; //to maintain current min sized window 
        
        //O(m) step
        while(j<s.size())
        {
            //Calculation of arr[j]
            if(hash.find(s[j]) != hash.end())
            {
                hash[s[j]] --;
                if(hash[s[j]]==0)
                    count--;
            }
            
            if(count > 0) 
                j++;
            
            else if(count == 0)
            {
                //we have a candidate answer and we will also try to optimise the string by removing useless characters
                while(count==0)
                {
                    if(j-i+1 < counter)
                    {
                        counter = j-i+1;
                        ans = {i,counter};
                    }
                    
                    if(hash.find(s[i]) != hash.end())
                    {
                        hash[s[i]] ++;
                        if(hash[s[i]]==1)
                            count++;
                    }
                    i++;
                }
                j++;
            } 
        }
        return (counter==INT_MAX) ? "" : s.substr(ans.first,ans.second);
    }
```
