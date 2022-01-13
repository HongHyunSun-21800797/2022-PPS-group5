class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int output = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            if(output < prices[i] - min_buy) {
                output = prices[i] - min_buy;
            } 
            if(prices[i] < min_buy) min_buy = prices[i];
        }
        
        return output;
    }
};