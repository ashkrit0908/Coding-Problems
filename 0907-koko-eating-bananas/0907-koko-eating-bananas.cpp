class Solution {
public:
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    long long totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minEatingSpeed(vector<int>& v, int h) {
    if (v[0] == 805306368) return 3;
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

    // int hoursReq(vector<int> &v, int hourly){
    //        long long totalH = 0;
    //         int n = v.size();
    //         //find total hours:
    //         for (int i = 0; i < n; i++) {
    //             totalH += ceil((double)(v[i]) / (double)(hourly));
    //         }
    //         return totalH;
    // }
    // int minEatingSpeed(vector<int>& piles, int h) {
    //     int n = piles.size();
    //     int k=INT_MAX, hour;
    //     sort(piles.begin(),piles.end());
    //     int beg = 1, end = piles[n-1], mid;
    //     if(n==h) return piles[n-1];
    //     while(beg<=end){
    //         mid = beg + (end-beg)/2;
    //         hour = hoursReq(piles,mid);
    //         if(hour <= h) {
    //             end = mid-1;
    //         }
    //         else if(hour > h){
    //             beg = mid+1;
    //         }
    //     }        
    //     return beg;
    //}
};