class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        double ans=0;
        int m = nums1.size();
        int n= nums2.size();
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] == nums2[j]){
                arr.push_back(nums1[i]);
                arr.push_back(nums2[j]);
                i++;
                j++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m) arr.push_back(nums1[i++]);
        while(j<n) arr.push_back(nums2[j++]);
        for(auto x : arr){
            cout<<x;
        }
        if (arr.size()%2 == 0){
            ans = (arr[(arr.size()/2)-1] + arr[arr.size()/2])/2.0;
            return ans;
        }
        else{
            ans =  arr[(arr.size()/2)];
            return ans;
        }
    }
};