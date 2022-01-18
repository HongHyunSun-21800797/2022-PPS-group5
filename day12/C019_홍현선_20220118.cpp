class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt1[27] = {0, };
        int cnt2[27] = {0, };
        
        for(int i = 0; i < s.size(); i++) cnt1[s[i]-'a']++;
        for(int i = 0; i < t.size(); i++) cnt2[t[i]-'a']++;
        
        for(int i = 0; i < 27; i++) {
            if(cnt1[i] != cnt2[i]) return false;
        }
        
        return true;
    }
};