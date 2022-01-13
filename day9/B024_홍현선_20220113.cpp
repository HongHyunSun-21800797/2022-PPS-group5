class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq; // <score, index>
        vector<string> v;
        int cnt = 1;
        
        for(int i = 0; i < score.size(); i++){
            string s;
            v.push_back(s);
        } 
        
        for(int i = 0; i < score.size(); i++) {
            pq.push(make_pair(score[i], i));
        }
        
        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            
            if(cnt == 1) v[idx] = "Gold Medal";
            else if(cnt == 2) v[idx] = "Silver Medal";
            else if(cnt == 3) v[idx] = "Bronze Medal";
            else v[idx] = to_string(cnt);
            
            cnt++;
        }
        return v;
    }
};