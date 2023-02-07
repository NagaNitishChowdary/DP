// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// PARTITIONS WITH GIVEN DIFFERENCE

#include <bits/stdc++.h> 
using namespace std;
int mod = (int)(1e9 + 7) ;

int memorization(int ind,int sum,vector<int> &arr,vector<vector<int>> &dp){
    if(ind == 0){
        if(sum == 0 && arr[0] == 0 ) return 2 ;
        if(sum == 0 || sum == arr[0]) return 1 ;
        return 0 ;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum] ;
    int notTake = memorization(ind-1,sum,arr,dp);
    int take = 0 ;
    if(arr[ind] <= sum) take = memorization(ind-1,sum-arr[ind],arr,dp);
    return dp[ind][sum] = (take + notTake)%mod ;
}

int findways(vector<int> &arr,int tar){
    // MEMORIZATION
    // vector<vector<int>> dp(arr.size(),vector<int> (tar+1,-1));
    // return memorization(arr.size()-1,tar,arr,dp);
    
    // TABULATION
    int n = arr.size() ;
    vector<vector<int>> dp(n,vector<int> (tar+1,0));
    if(arr[0] == 0) dp[0][0] = 2 ;
    else dp[0][0] = 1 ;
    if(arr[0] != 0 && arr[0] <= tar) dp[0][arr[0]] = 1 ;
    for(int ind=1 ; ind<n ; ind++ ){
        for(int sum=0 ; sum<=tar ; sum++){
            int notTake = dp[ind-1][sum] ;
            int take = 0 ;
            if(arr[ind] <= sum) take = dp[ind-1][sum-arr[ind]];
            dp[ind][sum] = (take + notTake)%mod ;
        }
    }
    return dp[n-1][tar] ;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    
   // APPROACH
   // GIVEN S1 - S2 = D 
   // S1 + S2 = TOTAL_SUM 
    // TOTAL_SUM - S2 - S2 = D 
    // TOTAL_SUM - D = 2 * S2
    // S2 = (TOTAL_SUM - D)/2 
    
    int totalSum = 0;
    for(auto &it:arr) totalSum += it ;
    if(totalSum - d < 0 || (totalSum-d)%2) return false ;
    return findways(arr,(totalSum-d)/2);
    
}

int main()
{
    int testCases; cin>>testCases;
    while(testCases--){
        int n,d; cin >> n>> d ;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin >> arr[i] ;
        cout << countPartitions(n,d,arr) << endl ;
    }
}


