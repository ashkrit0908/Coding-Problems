class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        if(nums.size()<3 || s.size()<3)
        {
            return *(max_element(nums.begin(),nums.end()));
        }
        priority_queue<int,vector<int>,greater<int>>minh;
        for(auto n:s)
        {
            minh.push(n);
            if(minh.size()>3)
            {
                minh.pop();
            }

        }
        return minh.top();
    }
};