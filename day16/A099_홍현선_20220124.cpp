vclass Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        
        for(int i = 0; i < S.size(); i++) {
            char p = S[i];
            
            if(p == ')') {
                if(s.empty() || s.top() != '(') return false;
                else s.pop();
            }
            else if(p == '(') s.push(p);
            else if(p == '}') {
                if(s.empty() || s.top() != '{') return false;
                else s.pop();
            }
            else if(p == '{') s.push(p);
            else if(p == ']') {
                if(s.empty() || s.top() != '[') return false;
                else s.pop();
            }
            else if(p == '[') s.push(p);
        }
        
        if(!s.empty()) return false;
        return true;
    }
};