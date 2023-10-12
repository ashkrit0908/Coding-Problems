class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result;
       int i=0;
        while(i<s.size()){
            if(s[i] == '('){
                if(!st.empty())  result.push_back(s[i]);
                st.push(s[i]);
                
            } 
            else if (s[i] == ')'){
                st.pop();
                if(!st.empty()){
                    result.push_back(s[i]);
                    
                }
            }
            
            i++;
        }
        return result;
        }
    
};