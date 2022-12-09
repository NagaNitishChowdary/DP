// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// PROBLEM LINK --- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int ind,int buy,vector<int> &prices,int n,int fee){
    if(ind >= n) return 0 ;
    if(buy){
        return max(-prices[ind] + recursion(ind+1,0,prices,n,fee) , 0 + recursion(ind+1,1,prices,n,fee)) ;
    }
    else{
        return max(prices[ind]-fee + recursion(ind+1,1,prices,n,fee) , 0 + recursion(ind+1,0,prices,n,fee)) ;
    }
}

int memoization(int ind,int buy,vector<int> &prices,int n,vector<vector<int>> &dp,int fee){
    if(ind >= n) return 0 ;
    if(dp[ind][buy] != -1) return dp[ind][buy] ;
    if(buy){
        return dp[ind][buy] = max(-prices[ind] + memoization(ind+1,0,prices,n,dp,fee) , 0 + memoization(ind+1,1,prices,n,dp,fee)) ;
    }
    else{
        return dp[ind][buy] = max(prices[ind]-fee + memoization(ind+1,1,prices,n,dp,fee) , 0 + memoization(ind+1,0,prices,n,dp,fee)) ;
    }
}

int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    // RECURSION
    // return recursion(0,1,prices,n,fee) ;
    
    // MEMOIZATION
    // vector<vector<int>> dp(n,vector<int>(2,-1)) ;
    // return memoization(0,1,prices,n,dp,fee) ;
    
    // TABULATION(OPPOSITE OF RECURSION)
    /*
    vector<vector<long>> dp(n+1,vector<long>(2,0)) ;
    // STEP 1 FOR TABULATION IS BASE CASE
    dp[n][0] = dp[n][1] = 0 ;
    for(long ind=n-1 ; ind>=0 ; ind--){
        for(long buy=0 ; buy<=1 ; buy++){
            long profit = 0 ;
            if(buy){
                profit = max(-prices[ind] + dp[ind+1][0] , 0 + dp[ind+1][1]) ;
            }
            else{
                profit = max(prices[ind] + dp[ind+1][1]-fee , 0 + dp[ind+1][0]) ;
            }
            dp[ind][buy] = profit ;
        }
    }
    return dp[0][1] ;
    */
    
    // SPACE OPTIMIZATION 1
    
    vector<long> ahead(2,0) , curr(2,0) ;
    ahead[0] = ahead[1] = 0 ;
    for(long ind=n-1 ; ind>=0 ; ind--){
        for(long buy=0 ; buy<=1 ; buy++){
            long profit = 0 ;
            if(buy){
                profit = max(-prices[ind] + ahead[0] , 0 + ahead[1]) ;
            }
            else{
                profit = max(prices[ind] + ahead[1] -fee , 0 + ahead[0]) ;
            }
            curr[buy] = profit ;
        }
        ahead = curr ;
    }
    return ahead[1] ;
    
}

int main()
{
    int testCases; cin >> testCases;
    while(testCases--){
        int n,fee ; cin >> n >> fee ;
        vector<int> prices(n) ;
        for(int i=0 ; i<n ; i++) cin >> prices[i] ;
        cout << maximumProfit(n,fee,prices) << endl ;
    }
}
