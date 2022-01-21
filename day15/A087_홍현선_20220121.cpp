class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int>> v;
        int output = 0;
        
        for(int i = 0; i < boxTypes.size(); i++) v.push_back(make_pair(boxTypes[i][1], boxTypes[i][0]));
        
        sort(v.begin(), v.end() );
        
        for(int i = v.size() - 1; i >= 0; i--) {
            if(truckSize == 0) break;
            
            if(truckSize >= v[i].second) {
                output += (v[i].first)*(v[i].second);
                truckSize -= v[i].second;
            }
            else {
                output += truckSize*v[i].first;
                truckSize = 0;
            }
        }
        
        return output;
    }
};