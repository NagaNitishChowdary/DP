// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://leetcode.com/problems/longest-increasing-subsequence/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1


#include<bits/stdc++.h>
using namespace std ;

int recursion(int ind,int prev_ind,int arr[],int n){
    if(ind == n) return 0 ;
    // NOT PICK 
    int notPick = 0 + recursion(ind+1,prev_ind,arr,n) ;
    // PICK 
    int pick = 0 ;
    if(prev_ind == -1 || arr[prev_ind] < arr[ind])
        pick = 1 + recursion(ind+1,ind,arr,n) ;
    return max(notPick , pick) ;
}

int memoization(int ind,int prev_ind,int arr[],int n,vector<vector<int>> &dp){
    if(ind == n) return 0 ;
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1] ;
    // NOT PICK 
    int notPick = 0 + memoization(ind+1,prev_ind,arr,n,dp) ;
    // PICK 
    int pick = 0 ;
    if(prev_ind == -1 || arr[prev_ind] < arr[ind])
        pick = 1 + memoization(ind+1,ind,arr,n,dp) ;
    return dp[ind][prev_ind+1] = max(notPick , pick) ;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // RECURSION
    // return recursion(0,-1,arr,n) ;
    
    // MEMOIZATION
    // IT GIVES RUN TIME ERROR AS CONSTRAINT N IS GIVEN AS
    // 10 POWER 5 AS THE VECTOR SIZE IS 10 POWER 10
    // vector<vector<int>> dp(n,vector<int>(n+1,-1)) ;
    // return memoization(0,-1,arr,n,dp) ;
    
    // TABULATION
    /*
    // STEP 1 --- BASE CASE 
    // IF IND == N THEN O ALREADY ALL ARE ZEROES
    vector<vector<int>> dp(n+1,vector<int>(n+1,0)) ;
    for(int ind = n-1 ; ind>=0 ; ind--){
        for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind--){
            int notPick = 0 + dp[ind+1][prev_ind+1] ;
    // PICK 
    int pick = 0 ;
    if(prev_ind == -1 || arr[prev_ind] < arr[ind])
        pick = 1 + dp[ind+1][ind+1] ;
     dp[ind][prev_ind+1] = max(notPick , pick) ;
        }
    }
    return dp[0][-1+1] ;
    */
        
    // SPACE OPTIMIZATION
    /*
    vector<int> ahead(n+1,0) , curr(n+1,0) ;
    for(int ind = n-1 ; ind>=0 ; ind--){
        for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind--){
            int notPick = 0 + ahead[prev_ind+1] ;
    // PICK 
    int pick = 0 ;
    if(prev_ind == -1 || arr[prev_ind] < arr[ind])
        pick = 1 + ahead[ind+1] ;
     curr[prev_ind+1] = max(notPick , pick) ;
        }
        ahead = curr ;
    }
    return curr[-1+1] ;
    */

    /*
    // TIME COMPLEXITY = O(N^2) 
    // SPACE COMPLEXITY = 0(N) 
    vector<int> dp(n,1) ;
    int maxi = 1 ;
    for(int ind=0 ; ind<n ; ind++){
        for(int prev_ind=0 ; prev_ind<ind ; prev_ind++){
            if(arr[prev_ind] < arr[ind]){
                dp[ind] = max(1+dp[prev_ind] , dp[ind]) ;
            }
        }
        maxi = max(maxi , dp[ind]) ;
    }
    return maxi ;
    */

    // PRINTING LONGEST INCREASING SUBSEQUENCE
    vector<int> dp(n,1) , hash(n) ;
    int maxi = 1 ;
    int last_index = 0 ;
    for(int ind=0 ; ind<n ; ind++){
        hash[ind] = ind ;
        for(int prev_ind=0 ; prev_ind<ind ; prev_ind++){
            if((arr[prev_ind] < arr[ind]) && (1 + dp[prev_ind])>dp[ind]){
                dp[ind] = 1+dp[prev_ind] ;
                hash[ind] = prev_ind ;
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind] ;
            last_index = ind ;
        }
    }
    vector<int> temp ;
    temp.emplace_back(arr[last_index]) ;
    while(hash[last_index] != last_index){
        last_index = hash[last_index] ;
        temp.emplace_back(arr[last_index]) ;
    }
    reverse(temp.begin(),temp.end()) ;
    for(auto it:temp) cout << it << " " ; 
    cout << endl ;
    return maxi ;
}

int main()
{
    int n ; cin >> n ;
    int arr[n] ;
    for(int i=0 ; i<n ; i++) cin >> arr[i] ;
    cout << longestIncreasingSubsequence(arr,n) << endl ; 
}
