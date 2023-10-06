class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = INT_MAX;
        int n = nums.size();
        int beg = 0, end = n-1, mid=0;
        while(beg <= end){
            mid = beg + (end-beg)/2;
            //left half sorted
            if(nums[mid]>=nums[beg]){
                s = min(s,nums[beg]);
                beg = mid+1;
            }
            // right half sorted
            else if(nums[mid]<nums[end]) {
                s = min(s,nums[mid]);
                end = mid-1;
            }

        }
        return s;
    }
};