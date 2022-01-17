class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        
        int pre_color = image[sr][sc];
        int R = image.size();
        int C = image[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        image[sr][sc] = newColor;
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        
        while(!q.empty()) {
            sr = q.front().first;
            sc = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int r = sr + dx[i];
                int c = sc + dy[i];
                
                if(r < 0 || r >= R) continue;
                if(c < 0 || c >= C) continue;
                
                if(image[r][c] == pre_color) {
                    image[r][c] = newColor;
                    q.push(make_pair(r, c));
                }
            }
            
        }
        
        return image;
    }
};