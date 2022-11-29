// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://leetcode.com/problems/distinct-subsequences/description/

// THE INTUTION BEHIND THIS IS THE IF AT THE INDICES THE CHARACTERS ARE EQUAL THEN SKIP BOTH PLUS ONLY SKIP THE FIRST STRING TO
// CHECK IF THERE IS ANOTHER MATHING CHARACTER OR ELSE IF IT DOES NOT MATCH SKIP THE CHARACTER OF THE FIRST STRING 

#include<bits/stdc++.h>
using namespace std ;

int recursion(int i,int j,string &s,string &t){
    if(j<0) return 1 ;
    if(i<0) return 0 ;
    if(s[i] == t[j]) return recursion(i-1,j-1,s,t) + recursion(i-1,j,s,t) ;
    return recursion(i-1,j,s,t) ;
}

int memorization(int i,int j,string &s,string &t,vector<vector<int>> &dp) {
    if(j<0) return 1 ;
    if(i<0) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s[i] == t[j]) return dp[i][j] = memorization(i-1,j-1,s,t,dp) + memorization(i-1,j,s,t,dp) ;
    return dp[i][j] = memorization(i-1,j,s,t,dp) ;
}

int numDistinct(string s, string t) {
    int n = s.size() ;
    int m = t.size() ;

    // RECURSION
    // return recursion(n-1,m-1,s,t) ;

    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(m,-1)) ;
    // return memorization(n-1,m-1,s,t,dp) ;

    // TABULATION
    /*
    vector<vector<double>> dp(n+1,vector<double>(m+1,0)) ;
    for(int i=0 ; i<=n ; i++) dp[i][0] = 1 ;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] 
            + dp[i-1][j] ;
            else dp[i][j] = dp[i-1][j] ;
        }
    }
    return (int)dp[n][m] ;
    */

    // SPACE OPTIMIZATION
    /*
    vector<double> prev(m+1,0) , curr(m+1,0) ;
    prev[0] = 1 ; curr[0] = 1 ;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(s[i-1] == t[j-1]) curr[j] = prev[j-1] 
            + prev[j] ;
            else curr[j] = prev[j] ;
        }
        prev = curr ;
    }
    return (int)curr[m] ;
    */
    
    // SPACE OPTIMIZATION TO 1D ARRAY 
    vector<double>  curr(m+1,0) ;
    curr[0] = 1 ;
    for(int i=1 ; i<=n ; i++){
        for(int j=m ; j>=1 ; j--){
            if(s[i-1] == t[j-1]) curr[j] = curr[j-1] 
            + curr[j] ;
            // else curr[j] = prev[j] ;
        }
        // prev = curr ;
    }
    return (int)curr[m] ;

}

int main() {
    int testCases; cin >> testCases ;
    while(testCases--){
        string str1,str2 ;
        cin >> str1 >> str2 ;
        cout << numDistinct(str1,str2) << "\n" ;
    }
}


