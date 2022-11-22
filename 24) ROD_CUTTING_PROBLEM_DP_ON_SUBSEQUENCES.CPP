#include<bits/stdc++.h>

int recursion(int ind,int n,vector<int> &price){
    if(ind == 0) return n*price[0] ;
    int notPick = 0 + recursion(ind-1,n,price) ;
    int pick = INT_MIN ;
    int rodLength = ind+1 ;
    if(rodLength <= n) pick = price[ind] + recursion(ind,n-rodLength,price) ;
    return max(pick,notPick) ;
}

int memorization(int ind,int n,vector<int> &prices,vector<vector<int>> &dp){
    if(ind == 0) return n*prices[0] ;
    if(dp[ind][n] != -1) return dp[ind][n] ;
    int notPick = 0 + memorization(ind-1,n,prices,dp) ;
    int pick = INT_MIN ;
    int rodLength = ind+1 ;
    if(rodLength <= n) pick = prices[ind] + memorization(ind,n-rodLength,prices,dp) ;
    return dp[ind][n] = max(pick,notPick) ;
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    // RECURSION
    // return recursion(n-1,n,price) ;
    
    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // return memorization(n-1,n,price,dp) ;
    
    // TABULATION
    /*
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int i=0 ; i<=n ; i++) dp[0][i] = i*price[0] ;
    for(int ind=1 ; ind<n ; ind++){
        for(int N=0 ; N<=n ; N++){
            int notPick = 0 + dp[ind-1][N] ;
            int pick = INT_MIN ;
            int rodLength = ind+1 ;
            if(rodLength <= N) pick = price[ind] + dp[ind][N-rodLength] ;
            dp[ind][N] = max(pick,notPick) ;
        }
    }
    return dp[n-1][n] ;
    */
    
    // SPACE OPTIMIZATION
    /*
    vector<int> prev(n+1,0) , curr(n+1,0) ;
    for(int i=0 ; i<=n ; i++) prev[i] = i*price[0] ;
    for(int ind=1 ; ind<n ; ind++){
        for(int N=0 ; N<=n ; N++){
            int notPick = 0 + prev[N] ;
            int pick = INT_MIN ;
            int rodLength = ind+1 ;
            if(rodLength <= N) pick = price[ind] + curr[N-rodLength] ;
            curr[N] = max(pick,notPick) ;
        }
        prev = curr ;
    }
    return prev[n] ;
    */
    
    // SPACE OPTIMIZATION 
    // INTO 1D ARRAY
    vector<int> prev(n+1,0) ;
    for(int i=0 ; i<=n ; i++) prev[i] = i*price[0] ;
    for(int ind=1 ; ind<n ; ind++){
        for(int N=0 ; N<=n ; N++){
            int notPick = 0 + prev[N] ;
            int pick = INT_MIN ;
            int rodLength = ind+1 ;
            if(rodLength <= N) pick = price[ind] + prev[N-rodLength] ;
            prev[N] = max(pick,notPick) ;
        }
    }
    return prev[n] ;
}
