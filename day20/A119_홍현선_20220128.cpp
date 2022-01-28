/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long hi = n;
        long long lo = 1;
        long long ans;
        
        while(lo <= hi) {
            long long mi = (lo+hi)/2;
            
            if(guess(mi) == 0) {
                ans = mi;
                break;
            }
            else if(guess(mi) == -1) hi = mi - 1;
            else lo = mi + 1;
        }
        
        return ans;
    }
};