class Solution {
public:
    bool shieve[5000001];
    
    int countPrimes(int n) {
        for(int i = 0; i <= n; i++) shieve[i] = true;
        
        int cnt = 0;
        shieve[0] = false;
        shieve[1] = false;
        
        for(int i = 2; i <= n; i++) {
            if(shieve[i]) {
                for(int j = i + i; j <= n; j += i) shieve[j] = false;
            }
        }
        
        for(int i = 2; i < n; i++) {
            if(shieve[i]) cnt++;
        }
        
        return cnt;
    }
};