// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/burst-balloons/1
// PROBLEM LINK --- https://leetcode.com/problems/burst-balloons/

#include <bits/stdc++.h>
using namespace std ;

int recursion(int i,int j,vector<int> &a){
    if(i > j) return 0 ;
    // even if i == j we must calculate so when overflown return 0 
    int maxi = INT_MIN ;
    for(int k=i ; k<= j ; k++){
        int cost = a[i-1]*a[k]*a[j+1] + recursion(i,k-1,a) + recursion(k+1,j,a) ;
        maxi = max(maxi, cost) ;
    }
    return maxi ;
}

int memoization(int i,int j,vector<int> &a,vector<vector<int>> &dp){
    if(i > j) return 0 ;
    // even if i == j we must calculate so when overflown return 0 
    int maxi = INT_MIN ;
    if(dp[i][j] != -1) return dp[i][j] ;
    for(int k=i ; k<= j ; k++){
        int cost = a[i-1]*a[k]*a[j+1] + memoization(i,k-1,a,dp) + memoization(k+1,j,a,dp) ;
        maxi = max(maxi, cost) ;
    }
    return dp[i][j] = maxi ;
}

int maxCoins(vector<int>& a)
{
    // Write your code here.
    int N = a.size() ;
    a.emplace_back(1) ;
    a.insert(a.begin(),1) ;
    // RECURSION
    // return recursion(1,N,a) ;
    // MEMOIZATION
    // vector<vector<int>> dp(N+1,vector<int> (N+1,-1)) ;
    // return memoization(1,N,a,dp) ;
    
    // TABULATION
    vector<vector<int>> dp(N+2,vector<int> (N+2,0)) ;
    for(int i=N ; i>=1 ; i--){
        // if j == n it gives run time error as j+1 in k loop so initialize vector n+2 size
        for(int j=1 ; j<=N ; j++){
            if(i>j) continue ;
            int maxi = INT_MIN ;
            // if(dp[i][j] != -1) return dp[i][j] ;
            for(int k=i ; k<= j ; k++){
                int cost = a[i-1]*a[k]*a[j+1] + dp[i][k-1] + dp[k+1][j] ;
                maxi = max(maxi, cost) ;
            }
            dp[i][j] = maxi ;
        }
    }
    return dp[1][N] ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> a(n) ;
        for(int i=0 ; i<n ; i++) cin >> a[i] ;
        cout << maxCoins(a) << endl ;
    }
    return 0 ;
}
