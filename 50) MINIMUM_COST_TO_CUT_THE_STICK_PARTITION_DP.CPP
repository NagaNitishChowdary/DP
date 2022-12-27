// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int i,int j,vector<int> &cuts){
    if(i > j) return 0 ;
    int mini = INT_MAX ;
    for(int k=i ; k<=j ; k++){
        int cost = cuts[j+1]-cuts[i-1] + recursion(i,k-1,cuts) + recursion(k+1,j,cuts) ;
        mini = min(mini , cost) ;
    }
    return mini ;
}

int memoization(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
    if(i > j) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int mini = INT_MAX ;
    for(int k=i ; k<=j ; k++){
        int cost = cuts[j+1]-cuts[i-1] + memoization(i,k-1,cuts,dp) + memoization(k+1,j,cuts,dp) ;
        mini = min(mini , cost) ;
    }
    return dp[i][j] = mini ;
}

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.emplace_back(n) ;
    cuts.insert(cuts.begin(),0) ;
    sort(cuts.begin() , cuts.end()) ;
    // RECURSION
    // return recursion(1,c,cuts) ;
    
    // MEMOIZATION
    // vector<vector<int>> dp(n,vector<int>(n,-1)) ;
    // return memoization(1,c,cuts,dp) ;
    
    // TABULATION
    vector<vector<int>> dp(c+2,vector<int>(c+2,0)) ;
    // CHANGE OF PARAMETERS IN REVERSE OF RECURSION
    for(int i=n ; i>=1 ; i--){
        for(int j=1 ; j<=c ; j++){
            // BASE CASE IF I>J NO NEED TO INITIALIZE TO 0 ALREADY O 
            if(i > j) continue ;
            int mini = INT_MAX ;
            for(int k=i ; k<=j ; k++){
                int cost = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j] ;
                mini = min(mini , cost) ;
            }
            dp[i][j] = mini ;
        }
    }
    return dp[1][c] ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n,c ; 
        cin >> n >> c ;
        vector<int> cuts(c) ;
        for(int i=0 ; i<c ; i++) cin >> cuts[i] ;
        cout << cost(n,c,cuts) << endl ;
    }
    return 0 ;
}
