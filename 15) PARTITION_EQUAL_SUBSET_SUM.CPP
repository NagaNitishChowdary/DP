#include<bits/stdc++.h>
using namespace std;

bool recursion(int ind,int target,vector<int>&arr){
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target ;
    bool notTake = recursion(ind-1 , target , arr);
    bool take = false ;
    if(arr[ind] <= target) take=recursion(ind-1,target-arr[ind] , arr);
    return take | notTake ;
}

bool tabulation(int n,int k,vector<int>&arr){
    // TABULATION
    // /*
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
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
    // */
}

bool spaceOptimization(int n,int k,vector<int>&arr){
    vector<int>prev(k+1,0) , curr(k+1,0) ;
    prev[0] = curr[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true ;
    for(int ind=1 ; ind<n ; ind++){
        for(int target=1 ; target <= k ; target++){
            bool notTake = prev[target] ;
            bool take = false;
            if(arr[ind] <= target) take = prev[target-arr[ind]];
            curr[target] = take | notTake ;
        }
        prev = curr ;
    }
    return prev[k] ;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int sum = 0;
    for(int i=0 ; i<n ; i++) sum += arr[i] ;  
    if(sum & 1) return false;
    int target = sum/2 ;
    // return recursion(n,target,arr);
    
    // return tabulation(n,target,arr);
    return spaceOptimization(n,target,arr);   
}
 
int main()
{
    int testCases; cin >> testCases;
    while(testCases--){
    int n; cin >> n;
    vector<int>arr(n);
    for(int i=0 ; i<n ;i++) cin >> arr[i] ;
    cout << canPartition(arr,n) << "\n" ;
    }
}
