class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;
        int ans = 0;
        
        for(auto c:text) {
            if(c == 'b') b++;
            else if(c == 'a') a++;
            else if(c == 'l') l++;
            else if(c == 'o') o++;
            else if(c == 'n') n++;
        }
        
        while(true) {
            if(b <= 0) break;
            else b--;
            
            if(a <= 0) break;
            else a--;
             
            if(l <= 1) break;
            else l -= 2;
            
            if(o <= 1) break;
            else o -= 2;
            
            if(n <= 0) break;
            else n--;
            
                
            ans++;
        }
        
        return ans;
    }
};