class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<int, vector<int>, greater<int>> A;
        priority_queue<int, vector<int>, greater<int>> B;
        int ans = 0;
        int INF = 987654321;
        
        for(int i = 0; i < costs.size(); i++) {
            ans += min(costs[i][0], costs[i][1]);
            int loss = abs(costs[i][0] - costs[i][1]);
                
            if(costs[i][0] < costs[i][1]) A.push(loss);
            else B.push(loss);
        }
        
        while(A.size() != B.size()) {
            if(A.size() > B.size()) {
                ans += A.top();
                B.push(INF);
                A.pop();
            }
            else {
                ans += B.top();
                A.push(INF);
                B.pop();
            }
        }
        
        return ans;
  }
};