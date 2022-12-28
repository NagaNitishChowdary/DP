// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/partition-array-for-maximum-sum/1?page=1&sortBy=accuracy
// PROBLEM LINK --- https://leetcode.com/problems/partition-array-for-maximum-sum/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/maximum-subarray_3755255?leftPanelTab=1

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int i,int n,int k,vector<int> &num){
    if(i == num.size()) return 0 ;
    int len = 0 ;
    int maxi = INT_MIN ;
    int maxAns = INT_MIN ;
    for(int j=i ; j<min(n,i+k) ; j++){
        len++ ;
        maxi = max(maxi , num[j]) ;
        int sum = len*maxi + recursion(j+1,n,k,num) ;
        maxAns = max(maxAns , sum) ;
    }
    return maxAns ;
}

int memoization(int i,int n,int k,vector<int> &num,vector<int> &dp){
    if(i == num.size()) return 0 ;
    if(dp[i] != -1) return dp[i] ;
    int len = 0 ;
    int maxi = INT_MIN ;
    int maxAns = INT_MIN ;
    for(int j=i ; j<min(n,i+k) ; j++){
        len++ ;
        maxi = max(maxi , num[j]) ;
        int sum = len*maxi + memoization(j+1,n,k,num,dp) ;
        maxAns = max(maxAns , sum) ;
    }
    return dp[i] = maxAns ;
}

int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n = num.size() ;
    // RECURSION
    // return recursion(0,n,k,num) ;
    // MEMOIZATION
    // vector<int> dp(n,-1) ;
    // return memoization(0,n,k,num,dp) ;
    // TABULATION
    vector<int> dp(n+1,0) ;
    dp[n] = 0 ;
    for(int i=n-1 ; i>=0 ; i--){
        int len = 0 ;
        int maxi = INT_MIN ;
        int maxAns = INT_MIN ;
        for(int j=i ; j<min(n,i+k) ; j++){
            len++ ;
            maxi = max(maxi , num[j]) ;
            int sum = len*maxi + dp[j+1] ;
            maxAns = max(maxAns , sum) ;
        }
        dp[i] = maxAns ;
    }
    return dp[0] ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n,k ; cin >> n >> k ;
        vector<int> num(n) ;
        for(int i=0 ; i<n ; i++) cin >> num[i] ;
        cout << maximumSubarray(num,k) << endl ;
    }
    return 0 ;
}
