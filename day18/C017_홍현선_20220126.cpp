class Solution {
public:
    int secondHighest(string s) {
        bool found[10] = {false, };
        int cnt = 0;
        int ans = -1;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') found[s[i]-'0'] = true;
        } 
        
        for(int i = 9; i >=0; i--) {
            if(found[i]) cnt++;
            
            if(cnt == 2) {
                ans = i;
                break;
            }
        }
         return ans;
    }
};