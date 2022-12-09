// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std ;

int recursion(int ind,int buy,int cap,vector<int> &prices,int n){
    if(ind == n || cap == 0) return 0 ;
    if(buy){
        return max(-prices[ind] + recursion(ind+1,0,cap,prices,n) , 0 + recursion(ind+1,1,cap,prices,n)) ;
    }
    else{
        return max(prices[ind] + recursion(ind+1,1,cap-1,prices,n) , 0 + recursion(ind+1,0,cap,prices,n)) ;
    }
}

int memoization(int ind,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
    if(ind == n || cap == 0) return 0 ;
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap] ;
    if(buy){
        return dp[ind][buy][cap] = max(-prices[ind] + memoization(ind+1,0,cap,prices,n,dp) , 0 + memoization(ind+1,1,cap,prices,n,dp)) ;
    }
    else{
        return dp[ind][buy][cap] = max(prices[ind] + memoization(ind+1,1,cap-1,prices,n,dp) , 0 + memoization(ind+1,0,cap,prices,n,dp)) ;
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    // RECURSION
    // return recursion(0,1,k,prices,n) ;
    
    // MEMOIZATION
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1))) ;
    // return memoization(0,1,k,prices,n,dp) ;
    
    // TABULATION
    /*
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0))) ;
    // STEP 1 WRITE BASECASES 
    // STEP 2 REPRESENT IN TERMS OF INDICES
    // STEP 3 COPY PASTE RECURSION
    for(int ind = n-1 ; ind>=0 ; ind--){
        for(int buy = 0 ; buy <=1 ; buy++){
            for(int cap = 1 ; cap<=k ; cap++){
                if(buy){
        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap] , 0 + dp[ind+1][1][cap]) ;
    }
    else{
        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1] , 0 + dp[ind+1][0][cap]) ;
    }
            }
        }
    }
    return dp[0][1][k] ;
    */
    
    // SPACE OPTIMIZATION
    vector<vector<int>> ahead(2,vector<int>(k+1,0)) , curr(2,vector<int>(k+1,0)) ;
    for(int ind = n-1 ; ind>=0 ; ind--){
        for(int buy = 0 ; buy <=1 ; buy++){
            for(int cap = 1 ; cap<=k ; cap++){
                if(buy){
        curr[buy][cap] = max(-prices[ind] + ahead[0][cap] , 0 + ahead[1][cap]) ;
    }
    else{
        curr[buy][cap] = max(prices[ind] + ahead[1][cap-1] , 0 + ahead[0][cap]) ;
    }
            }
        }
        ahead = curr ;
    }
    return curr[1][k] ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
    int n,k ; cin >> n >> k ;
    vector<int> prices(n) ;
    for(int i=0 ; i<n ; i++) cin >> prices[i] ;
    cout << maximumProfit(prices,n,k) << endl ;
}
}
