// THIS PROBLEM IS SAME AS THE DIFFERENCE BETWEEN SUBSETS IS 
// TARGET i.e  S1 - S2 = X 
// S1 + S2 = TOTALSUM
// S1 = TOTALSUM - S2 
// TOTALSUM - S2 - S2 = X 
// S2 = (TOTALSUM - X)/2 

#include<bits/stdc++.h>
using namespace std;

int recursion(int ind,int target,vector<int> &arr){
    if(ind == 0){
        if(target == 0 && arr[0] == 0) return 2 ;
        if(target == 0 || target == arr[0]) return 1 ;
        else return 0 ;
    }
    //if(dp[ind][target] != -1) return dp[ind][target] ;
    int notPick = recursion(ind-1,target,arr);
    int pick = 0 ;
    if(arr[ind] <= target) pick = recursion(ind-1,target-arr[ind],arr);
    return pick + notPick ;
}

int memorization(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(ind == 0){
        if(target == 0 && arr[0] == 0) return 2 ;
        if(target == 0 || arr[0] == target) return 1 ;
        else return 0 ;
    }
    if(dp[ind][target] != -1) return dp[ind][target] ;
    int notPick = memorization(ind-1,target,arr,dp);
    int pick = 0 ;
    if(arr[ind] <= target) pick = memorization(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] = pick + notPick ;
}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    // RECURSION
    // vector<vector<int>> dp(n,vector<int> (target+1,-1));
    // int totalsum = 0 ;
    // for(int i=0 ; i<n ; i++) totalsum += arr[i] ;
    // if((totalsum - target)%2 || totalsum-target < 0) return 0 ;
    // else return recursion(n-1,(totalsum-target)/2,arr) ;
    
    // MEMORIZATION
    // int totalsum = 0;
    // for(int i=0 ; i<n ; i++) totalsum += arr[i] ;
    // vector<vector<int>> dp(n,vector<int>((totalsum-target)/2+1,-1));
    // if((totalsum - target)%2 || (totalsum - target)<0) return 0 ;
    // else return memorization(n-1,(totalsum - target)/2,arr,dp);
    
    // TABULATION
    /*
    int totalsum = 0;
    for(int i=0 ; i<n ; i++) totalsum += arr[i] ;
    if((totalsum-target)%2 || (totalsum-target)<0) return 0;
    else target = (totalsum-target)/2 ;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    if(arr[0] == 0) dp[0][0] = 2 ;
    else dp[0][0] = 1 ;
    if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
    for(int ind=1 ; ind<n ; ind++){
        for(int tar=0 ; tar<=target ; tar++){
            int notPick = dp[ind-1][tar] ;
            int pick = 0;
            if(arr[ind] <= tar) pick = dp[ind-1][tar-arr[ind]];
            dp[ind][tar] = pick + notPick ;
        }
    }
    return dp[n-1][target] ;
    */
    
    // SPACE OPTIMIZATION
     int totalsum = 0;
    for(int i=0 ; i<n ; i++) totalsum += arr[i] ;
    if((totalsum-target)%2 || (totalsum-target)<0) return 0;
    else target = (totalsum-target)/2 ;
    // vector<vector<int>> dp(n,vector<int>(target+1,0));
    vector<int> prev(target+1,0) , curr(target+1,0) ;
    if(arr[0] == 0) prev[0] = 2 ;
    else prev[0] = 1 ;
    if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;
    for(int ind=1 ; ind<n ; ind++){
        for(int tar=0 ; tar<=target ; tar++){
            int notPick = prev[tar] ;
            int pick = 0;
            if(arr[ind] <= tar) pick = prev[tar-arr[ind]];
            curr[tar] = pick + notPick ;
        }
        prev = curr ;
    }
    return prev[target] ;
}

int main()
{
    int testCases; cin >> testCases;
    while(testCases--){
        int n,target ;
        cin >> n >> target ;
        vector<int> arr(n) ;
        for(int i=0 ; i<n ; i++) cin >> arr[i] ;
        cout << targetSum(n,target,arr) << "\n" ;
    }
}

