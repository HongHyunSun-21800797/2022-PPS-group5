class Solution {
public:
    int balancedStringSplit(string s) {
        int r = 0;
        int c = 0;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'R') r++;
            else c++;
            
            if(r == c) {
                result++;
                r = 0;
                c = 0;
            }
        }
        
        return result;
    }
};