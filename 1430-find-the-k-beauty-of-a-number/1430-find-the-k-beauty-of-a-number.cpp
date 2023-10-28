class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        int i=0;
        while(i+k <= s.size()){
            string subString = s.substr(i,k); 
            int temp = stoi(subString);
            cout<<temp<<" ";
            if(temp != 0 && num%temp == 0) ans++;
            i++;
        }
        return ans;
    }
};