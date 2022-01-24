class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int pre_r = matrix.size();
        int pre_c = matrix[0].size();
        
        for(int i = 0; i < pre_c; i++) {
            vector<int> v;
            for(int j = 0; j < pre_r; j++) v.push_back(0);
            ans.push_back(v);
        }
        
        for(int r = 0; r < pre_c; r++) {
            for(int c = 0; c < pre_r; c++) ans[r][c] = matrix[c][r];
        }
        
        return ans;
    }
};