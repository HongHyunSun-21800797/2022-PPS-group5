class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i = 1; i <= numRows; i++) {
            vector<int> v;
            for(int j = 0; j < i; j++) v.push_back(0);
            v[0] = 1;
            v[i-1] = 1;
            ans.push_back(v);
        }
        
        for(int i = 0; i < numRows; i++) {
            if(i == 0 || i == 1) continue;
            
            for(int j = 1; j < i; j++) ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
        
        return ans;
    }
};