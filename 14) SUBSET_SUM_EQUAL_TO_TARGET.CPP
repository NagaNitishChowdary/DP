// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

// SUBSET SUM EQUAL TO TARGET
// *** THE TABULATION OF LAST ROW(N-1 TH ROW) TELLS THAT IN BETWEEN 0 TO TARGET RANGE IN WHICH SUMS CAN BE ACHIEVED 
// IF DP[N-1][SUM] == TRUE THEN THAT SUM CAN BE OBTAINED THROUGH THE SUBSETS

#include <bits/stdc++.h>
using namespace std;

bool recursion1(int ind,int n,int k,vector<int>&arr,int sum){
    if(ind >= n){
        if(sum == k) return true;
        else return false;
    }
    sum += arr[ind] ;
    if(recursion1(ind+1,n,k,arr,sum) == true) return true;
    sum -= arr[ind] ;
    if(recursion1(ind+1,n,k,arr,sum) == true) return true;
    return false;
}

bool recursion2(int ind,int target,vector<int>&arr){
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target ;
    bool notTake = recursion2(ind-1 , target , arr);
    bool take = false;
    if(arr[ind] <= target) take = recursion2(ind-1 , target-arr[ind] , arr);
    return take | notTake ;
}

bool memorization(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target == 0) return true ;
    if(ind == 0) return arr[0] == target ;
    if(dp[ind][target] != -1) return dp[ind][target];
    bool notTake = memorization(ind-1 , target , arr, dp);
    bool take = false ;
    if(arr[ind] <= target) take = memorization(ind-1 , target-arr[ind] , arr,dp);
    return dp[ind][target] = notTake | take ;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    // return recursion1(0,n,k,arr,0);
    
    // return recursion2(n-1,k,arr);
    
    // MEMORIZATION 
    // vector<vector<int>>dp(n,vector<int>(k+1 , -1));
    // return memorization(n-1,k,arr,dp);
    
    // TABULATION
    /*
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int ind = 1 ; ind < n ; ind++){
        for(int target = 1 ; target <= k ; target ++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) 
                take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take | notTake ;
        }
    }
    return dp[n-1][k] ;
    */
    
    // SPACE OPTIMIZATION
    vector<bool>prev(k+1,0) , curr(k+1,0) ;
    prev[0] = curr[0] = true ;
    prev[arr[0]] = true ;
    for(int ind = 1 ; ind < n ; ind++){
        for(int target = 1 ; target <= k ; target++){
            bool notTake = prev[target] ;
            bool take = false ;
            if(arr[ind] <= target)
                take = prev[target-arr[ind]] ;
            curr[target] = take | notTake ;
        }
        prev = curr ;
    }
    return prev[k] ;
}

int main()
{
    int testCases; cin >> testCases;
    while(testCases--){
        int n,target ; cin >> n >> target;
        vector<int>arr(n);
        for(int i =0 ;i<n ; i++) cin >> arr[i] ;
        cout << subsetSumToK(n,target,arr) << "\n";
    }
}
