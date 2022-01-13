#include <cmath>
class Solution {
public:
    int process(int n) {
        int output = 0;
        string input = to_string(n);
        
        for(auto i: input) {
            output += pow((i-'0'),2);
        }
        return output;
    }
    
    bool isHappy(int n) {
        bool output = false;
        vector<int> accum;
        accum.push_back(-1);
        
        if(n == 1) output = true;
        
        while(find(accum.begin(), accum.end(), n) == accum.end() && n != 1) {
            accum.push_back(n);
            n = process(n);
            
            if(n == 1) output = true;
     
        }
        
        return output;
        
    }
};