class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     int n=nums.size(),sum=0,ans=0;
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        if(n==3)
            return nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int first=nums[i];
            int s=i+1,e=n-1;
            while(s<e)
            {
                sum=first+nums[s]+nums[e];
                if(sum==target) return target;
                else if(abs(target-sum)<diff){
                    diff=abs(target-sum);
                    ans=sum;
                }
                if(sum>target)
                    e--;
                else
                    s++;
            }
        }
            return ans;
        }
};