class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int n = nums.size();
        int beg = 0, end = n-1,mid=0;
        while(beg<=end){
            mid = beg + (end-beg)/2;
            if(nums[mid] == k) return true;
            if(nums[beg] == nums[mid] && nums[mid] == nums[end]){
                beg = beg+1;
                end = end-1;
                continue;
            }
            if(nums[beg]<=nums[mid]){
                if(nums[beg] <= k && k<=nums[mid]){
                    end = mid-1;
                }
                else beg = mid+1;
            }
            else{
                if(nums[end] >= k && k>= nums[mid]){
                    beg = mid+1;
                }
                else end = mid-1;
            }
        }
        return false;
    }
};