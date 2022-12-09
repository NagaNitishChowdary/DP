// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/buy-stock-with-cooldown/1?page=1&sortBy=newest&query=page1sortBynewest

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int ind,int buy,vector<int> &prices,int n){
    if(ind >= n) return 0 ;
    if(buy){
        return max(-prices[ind] + recursion(ind+1,0,prices,n) , 0 + recursion(ind+1,1,prices,n)) ;
    }
    else{
        return max(prices[ind] + recursion(ind+2,1,prices,n) , 0 + recursion(ind+1,0,prices,n)) ;
    }
}

int memoization(int ind,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){
    if(ind >= n) return 0 ;
    if(dp[ind][buy] != -1) return dp[ind][buy] ;
    if(buy){
        return dp[ind][buy] = max(-prices[ind] + memoization(ind+1,0,prices,n,dp) , 0 + memoization(ind+1,1,prices,n,dp)) ;
    }
    else{
        return dp[ind][buy] = max(prices[ind] + memoization(ind+2,1,prices,n,dp) , 0 + memoization(ind+1,0,prices,n,dp)) ;
    }
}

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size() ;
    // RECURSION
    // return recursion(0,1,prices,n) ;
    
    // MEMOIZATION
    // vector<vector<int>> dp(n,vector<int>(2,-1)) ;
    // return memoization(0,1,prices,n,dp) ;
    
    // TABULATION
    /*
    vector<vector<int>> dp(n+1,vector<int>(2,0)) ;
    // STEP 1 WRITE BASECASES 
    // STEP 2 REPRESENT IN TERMS OF INDICES
    // STEP 3 COPY PASTE RECURSION
    for(int ind = n-1 ; ind>=0 ; ind--){
        for(int buy = 0 ; buy <=1 ; buy++){
                if(buy){
        dp[ind][buy] = max(-prices[ind] + dp[ind+1][0] , 0 + dp[ind+1][1]) ;
    }
    else{
        // dp[ind][buy] = 0 ;
        int knnc = prices[ind] ;
        if(ind < n-1) knnc += dp[ind+2][1] ;
         dp[ind][buy] = max(knnc , 0 + dp[ind+1][0]) ;
    }
            }
    }
    return dp[0][1] ;
    */
    
    // SPACE OPTIMIZATION
    vector<int> ahead(2,0) , curr(2,0) , aheadahead(2,0) ;
    for(int ind = n-1 ; ind>=0 ; ind--){
        for(int buy = 0 ; buy <=1 ; buy++){
            // for(int cap = 1 ; cap<=k ; cap++){
                if(buy){
        curr[buy] = max(-prices[ind] + ahead[0] , 0 + ahead[1]) ;
    }
    else{
        int knnc = prices[ind] ;
        if(ind < n-1) knnc += aheadahead[1] ;
        curr[buy] = max(knnc, 0 + ahead[0]) ;
    }
            //}
        }
        aheadahead = ahead ;
        ahead = curr ;
    }
    return curr[1] ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n; cin >> n ;
        vector<int> prices(n) ;
        for(int i=0 ; i<n ; i++) cin >> prices[i] ;
        cout << stockProfit(prices) << endl ;
    }
}
