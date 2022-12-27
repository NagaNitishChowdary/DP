// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int i,int j,vector<int> &arr){
    // BASE CASE 
    if(i == j) return 0 ;
    int mini = (int)10e9 ;
    for(int k=i ; k<j ; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + recursion(i,k,arr) + recursion(k+1,j,arr) ;
        mini = min(mini , steps) ;
    }
    return mini ;
}

int memoization(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(i == j) return dp[i][j] = 0 ;
    int mini = (int)10e9 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    for(int k=i ; k<j ; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + memoization(i,k,arr,dp) + memoization(k+1,j,arr,dp) ;
        mini = min(mini , steps) ;
    }
    return dp[i][j] = mini ;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    // RECURSION
    // return recursion(1,N-1,arr) ;
    // MEMOIZATION
    // vector<vector<int>> dp(N,vector<int>(N,-1)) ;
    // return memoization(1,N-1,arr,dp) ;
    
    // TABULATION
    int dp[N][N] ;
    // BASE CASE
    for(int i=0 ; i<N ; i++) dp[i][i] = 0 ;
    // CHANGING VARIABLES
    for(int i=N-1 ; i>=1 ; i--){
        // I SHOULD BE BEFORE J 
        for(int j=i+1 ; j<=N ; j++){
            int mini = (int)10e9 ;
            for(int k=i ; k<j ; k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j] ;
                mini = min(mini , steps) ;
            }
        dp[i][j] = mini ;
        }
    }
    return dp[1][N-1] ;
}

int main(){
    int testCases ; cin >> testCases ;
    while(testCases--){
        int N ; cin >> N ;
        vector<int> arr(N) ;
        for(int i=0 ; i<N ; i++) cin >> arr[i] ;
        cout << matrixMultiplication(arr , N) << endl ;
    }
    return 0 ;
}
