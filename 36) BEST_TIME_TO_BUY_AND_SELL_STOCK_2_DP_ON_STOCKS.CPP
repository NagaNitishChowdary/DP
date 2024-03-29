// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// PROBLEM LINK --- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include<bits/stdc++.h>
using namespace std ;

long recursion(int ind,int buy,long *values,int n){
    if(ind == n) return 0 ;
    long profit = 0 ;
    if(buy){
        profit = max(-values[ind] + recursion(ind+1,0,values,n) , 0 + recursion(ind+1,1,values,n)) ;
    }
    else{
        profit = max(values[ind] + recursion(ind+1,1,values,n) , 0 + recursion(ind+1,0,values,n)) ;
    }
    return profit ;
}

long memoization(long ind,long buy,long *values,long n,vector<vector<long>> &dp){
    if(ind == n) return 0 ;
    if(dp[ind][buy] != -1) return dp[ind][buy] ;
    long profit = 0 ;
    if(buy){
        profit = max(-values[ind] + memoization(ind+1,0,values,n,dp) , 0 + memoization(ind+1,1,values,n,dp)) ;
    }
    else{
        profit = max(values[ind] + memoization(ind+1,1,values,n,dp) , 0 + memoization(ind+1,0,values,n,dp)) ;
    }
    return dp[ind][buy] = profit ;
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    // RECURSION    
    // return recursion(0,1,values,n) ;
    
    // MEMOIZATION
    // vector<vector<long>> dp(n,vector<long>(2,-1)) ;
    // return memoization(0,1,values,n,dp) ;
     
    // TABULATION(OPPOSITE OF RECURSION)
    /*
    vector<vector<long>> dp(n+1,vector<long>(2,0)) ;
    // STEP 1 FOR TABULATION IS BASE CASE
    dp[n][0] = dp[n][1] = 0 ;
    for(long ind=n-1 ; ind>=0 ; ind--){
        for(long buy=0 ; buy<=1 ; buy++){
            long profit = 0 ;
            if(buy){
                profit = max(-values[ind] + dp[ind+1][0] , 0 + dp[ind+1][1]) ;
            }
            else{
                profit = max(values[ind] + dp[ind+1][1] , 0 + dp[ind+1][0]) ;
            }
            dp[ind][buy] = profit ;
        }
    }
    return dp[0][1] ;
    */
    
    // SPACE OPTIMIZATION 1
    /*
    vector<long> ahead(2,0) , curr(2,0) ;
    ahead[0] = ahead[1] = 0 ;
    for(long ind=n-1 ; ind>=0 ; ind--){
        for(long buy=0 ; buy<=1 ; buy++){
            long profit = 0 ;
            if(buy){
                profit = max(-values[ind] + ahead[0] , 0 + ahead[1]) ;
            }
            else{
                profit = max(values[ind] + ahead[1] , 0 + ahead[0]) ;
            }
            curr[buy] = profit ;
        }
        ahead = curr ;
    }
    return ahead[1] ;
    */
    
    // TIME OPTIMIZATION(O(N))
    long aheadNotBuy , aheadBuy , currNotBuy , currBuy ;
    aheadNotBuy = aheadBuy = 0 ;
    for(int ind=n-1 ; ind>=0 ; ind--){
        currNotBuy = max(values[ind]+aheadBuy , aheadNotBuy) ;
        currBuy = max(-values[ind]+aheadNotBuy , aheadBuy) ;
        aheadBuy = currBuy ;
        aheadNotBuy = currNotBuy ;
    }
    return aheadBuy ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n ;
        long values[n] ;
        for(int i=0 ; i<n ; i++) cin >> values[i] ;
        cout << getMaximumProfit(values , n) << "\n" ;
    }
    return 0 ;
}
