// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// INTUTION BEHIND THIS IS SIMPLY FIND LONGEST COMMON SUBSEQUENCE AND RETURN LENGTH OF STRING 1 MINUS LENGTH OF LCS PLUS LENGTH OF STRING 2 MINUS LENGTH OF LCS 

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int i,int j,string &str,string &ptr){
    if(i<0 || j<0) return 0 ;
    if(str[i] == ptr[j]) return 1 + recursion(i-1,j-1,str,ptr);
    return max(recursion(i-1,j,str,ptr),recursion(i,j-1,str,ptr)) ;
}

int memorization(int i,int j,string &str,string &ptr,vector<vector<int>> &dp){
    if(i<0 || j<0) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(str[i] == ptr[j]) return 1 + memorization(i-1,j-1,str,ptr,dp) ;
    return dp[i][j] = max(memorization(i-1,j,str,ptr,dp) , memorization(i,j-1,str,ptr,dp)) ;
}

int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size() ;
    int m = ptr.size() ;
    
    // RECURSION
    // int ans = recursion(n-1,m-1,str,ptr) ;
    // return m - ans + n - ans ;
    
    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(m,-1)) ;
    // int ans = memorization(n-1,m-1,str,ptr,dp) ;
    // return m - ans + n - ans ;
    
    // TABULATION
    /*
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(str[ind1-1] == ptr[ind2-1]) dp[ind1][ind2]=1 + dp[ind1-1][ind2-1] ;
            else dp[ind1][ind2] = max(dp[ind1-1][ind2] , dp[ind1][ind2-1]) ;
        }
    }
    return m - dp[n][m] + n - dp[n][m] ;
    */
    
    // SPACE OPTIMIZATION
    vector<int> prev(m+1.0) , curr(m+1,0) ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(str[ind1-1] == ptr[ind2-1]) curr[ind2]=1 + prev[ind2-1] ;
            else curr[ind2] = max(prev[ind2] , curr[ind2-1]) ;
        }
        prev = curr ;
    }
    return m - curr[m] + n - curr[m] ;
    
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        string str1,str2 ;
        cin >> str1 >> str2 ;
        cout << canYouMake(str1,str2) << "\n" ;
    }
}
