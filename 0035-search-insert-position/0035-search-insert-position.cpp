class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size()-1, mid = 0, ans = nums.size();
        
        while(beg<=end){
            int mid = beg + (end-beg)/2;
            if (nums[mid] >= target){
                ans = mid;
                end = mid-1;
            }
            else {
                beg = mid+1;
            }
        }
        return ans;
           
    }
};