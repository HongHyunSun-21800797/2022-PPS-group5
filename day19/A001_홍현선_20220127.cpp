class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int cookie = 0;
        
        for(int i = 0; i < g.size(); i++) {
            while(cookie != s.size() && g[i] > s[cookie]) cookie++;
            
            if(cookie == s.size()) break;
            if(g[i] <= s[cookie]) {
                ans++;
                cookie++;
            }
        }
        
        return ans;
    }
    
};