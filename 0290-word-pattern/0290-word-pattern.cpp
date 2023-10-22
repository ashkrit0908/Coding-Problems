class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        vector<string> word;
        int i=0;
        string temp="";
        while(i<s.size())
        {
            if(s[i] == ' ')
            {
                word.push_back(temp);
                temp="";
            }
            else
            {
                temp+=s[i];
            }
            i++;
        }
        word.push_back(temp);
        if(word.size()!=pattern.size())
        {
            return false;
        }
        set<string> st;
        for(int i=0;i<pattern.size();i++)
        {
            if(m.find(pattern[i])!=m.end())
            {
                if(m[pattern[i]]!=word[i])
                {
                    return false;
                }
            }
            else
            {
                if(st.count(word[i])>0)
                {
                    return false;
                }
                st.insert(word[i]);
                m[pattern[i]]=word[i];
            }
            
        }
        return true;
    }
};