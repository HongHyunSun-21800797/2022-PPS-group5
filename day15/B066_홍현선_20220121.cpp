class Solution {
public:
    void reverseString(vector<char>& s) {
        int n;
        if(s.size() % 2 == 0) n = s.size()/2;
        else n = (s.size()+1)/2;
        
        for(int i = 0; i < n; i++) {
            char temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = temp;
        }
     
    }
};