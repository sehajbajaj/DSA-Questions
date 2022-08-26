class Solution {
public:
    int findSquare(int n){
        int ans = 0;
        
        while(n > 0){
            int rem = n % 10;
            ans += rem * rem;
            n /= 10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        if(n < 0){
            return false;
        }
        
        int slow = n;
        int fast = n;
    
        do{
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        }while(slow != fast);
        
        return slow == 1 ? true : false;
    }
};