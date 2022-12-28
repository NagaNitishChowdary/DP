// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_873266?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// PROBLEM LINK --- https://leetcode.com/problems/palindrome-partitioning-ii/

#include <bits/stdc++.h> 
using namespace std ;

bool isPalindrome(int i,int j,string str){
    int n = str.size() ;
    while(i<j){
        if(str[i] != str[j]) return false ;
        i++ ; j-- ;
    }
    return true ;
}

int recursion(int i,int n,string &str){
    if(i == n) return 0 ;
    int minCost = INT_MAX ;
    for(int j=i ; j<n ; j++){
        if(isPalindrome(i,j,str)){
            int cost = 1 + recursion(j+1,n,str) ;
            minCost = min(minCost , cost) ;
        }
    }
    return minCost ;
}

int memoization(int i,int n,string &str,vector<int> &dp){
    if(i == n) return 0 ;
    if(dp[i] != -1) return dp[i] ;
    int minCost = INT_MAX ;
    for(int j=i ; j<n ; j++){
        if(isPalindrome(i,j,str)){
            int cost = 1 + memoization(j+1,n,str,dp) ;
            minCost = min(minCost , cost) ;
        }
    }
    return dp[i] = minCost ;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size() ;
    // RECURSION
    // -1 to answer as it partitions the last letter also 
    // return recursion(0,n,str)-1 ;
    // MEMOIZATION
    // vector<int> dp(n,-1) ;
    // return memoization(0,n,str,dp)-1 ;
    // TABULATION
    vector<int> dp(n+1,0) ;
    // dp[n] = 0 ;
    for(int i=n-1 ; i>=0 ; i--){
        int minCost = INT_MAX ;
        for(int j=i ; j<n ; j++){
            if(isPalindrome(i,j,str)){
                int cost = 1 + dp[j+1] ;
                minCost = min(minCost , cost) ;
            }
        }
        dp[i] = minCost ;
    }
    return dp[0]-1 ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        string str ; cin >> str ;
        cout << palindromePartitioning(str) << endl ;
    }
}
