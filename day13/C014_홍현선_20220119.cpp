class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       priority_queue<int, vector<int>, greater<int>> pq[27];
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++) {
            int cnt[27] = {0, };
            
            for(int j = 0; j < words[i].size(); j++) cnt[words[i][j]-'a']++;
            
            for(int j = 0; j < 27; j++) pq[j].push(cnt[j]); 
        }
        
        for(int i = 0; i < 27; i++) {
            if(pq[i].top() == 0) continue;
            string s = "";
            
            s.push_back('a'+i);
            
            for(int j = 0; j < pq[i].top(); j++) ans.push_back(s);
        }
        
        return ans;
    }
};