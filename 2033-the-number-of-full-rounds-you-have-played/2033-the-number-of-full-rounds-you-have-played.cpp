class Solution {
public:
    int minConvert(string &time){
        return stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
    }

    int numberOfRounds(string loginTime, string logoutTime) {
        int start = minConvert(loginTime), end = minConvert(logoutTime);

        if (start > end) end += 1440;
        if (start % 15) start=(start/15 + 1)*15;
        
        return abs(end - start)/15;
        
    }
};