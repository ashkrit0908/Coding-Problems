class Solution {
public:
bool subsetSum(vector<int> arr, int sum, int n){
    bool t[n+1][sum+1];
            for(int i=0; i<=sum; i++){
                t[0][i] = 0;
            }
            for(int i=1; i<=n; i++){
                t[i][0] = 1;
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=sum; j++){
                    if(arr[i-1] <= j){
                        t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                    }
                    else{
                        t[i][j] = t[i-1][j];
                    }
                }
            }
    return t[n][sum];
}
    bool canPartition(vector<int>& arr) {
        int n= arr.size();
        int sum = 0;
        for (auto x : arr){
            sum += x;
        }
        if (sum%2 != 0){
            return false;
        }
        else{
            return subsetSum(arr, sum/2, n);
        }
    }
};