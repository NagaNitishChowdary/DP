// PROBLEM LINK --- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int ind,int buy,int cap,vector<int> &prices,int n){
    if(ind == n || cap == 0) return 0 ;
    if(buy){
        return max(-prices[ind]+recursion(ind+1,0,cap,prices,n) , 0+recursion(ind+1,1,cap,prices,n)) ;
    }
    else{
        return max(prices[ind]+recursion(ind+1,1,cap-1,prices,n) , 0+recursion(ind+1,0,cap,prices,n)) ;
    }
}

int memoization(int ind,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
    if(ind == n || cap == 0) return 0 ;
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap] ;
    if(buy){
        return dp[ind][buy][cap] = max(-prices[ind]+memoization(ind+1,0,cap,prices,n,dp) , 0+memoization(ind+1,1,cap,prices,n,dp)) ;
    }
    else{
        return dp[ind][buy][cap] = max(prices[ind]+memoization(ind+1,1,cap-1,prices,n,dp) , 0+memoization(ind+1,0,cap,prices,n,dp)) ;
    }
}

int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    // RECURSION
    // return recursion(0,1,2,prices,n) ;
    
    // MEMOIZATION
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1))) ;
    // return memoization(0,1,2,prices,n,dp) ;

    // TABULATION
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0))) ;
    // STEP 1 --- WRITE BASECASES
    // BASECASE 1 --- IF CAP == 0 THEN BUY AND IND CAN BE ANYTHING HENCE WE RUN CAP LOOP FROM 1 TO 2 EXCLUDING 0
    // BASECASE 2 --- IF IND == N THEN CAP AND BUY CAN BE ANYTHING HENCE WE RUN IND LOOP FROM N-1 
    for(int ind=n-1 ; ind>=0 ; ind--){
        for(int buy=0 ; buy<=1 ; buy++){
            for(int cap=1 ; cap<=2 ; cap++){
                if(buy){
                    dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap] , 0+dp[ind+1][1][cap]) ;
                }
                else{
                    dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1] , 0+dp[ind+1][0][cap] );
            }
            }
        }
    }
    return dp[0][1][2] ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n ;
        vector<int> prices(n) ;
        for(int i=0 ; i<n ; i++) cin >> prices[i] ;
        cout << maxProfit(prices,n) << endl ;
    }
    return 0 ;
}
