class Solution {
public:
    long long sum(long long k) {
        return k*(k+1)/2;
    }
    
    int arrangeCoins(int n) {
        long long lo = 1;
        long long hi = n;
        long long staircase = 0;
        
        while(lo <= hi) {
            long long mi = (lo+hi)/2;
            
            if(sum(mi) <= n) {
                if(mi > staircase) staircase = mi;
                lo = mi + 1;
                
            }
            else hi = mi - 1;
            
        } 
        
        return staircase;
    }
};