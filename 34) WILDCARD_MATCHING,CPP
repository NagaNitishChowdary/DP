// PROBLEM LINK --- https://leetcode.com/problems/wildcard-matching/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std ;

bool recursion(int i,int j,string &pattern,string &text){
    if(i<0 && j<0) return true ;
    if(i<0 && j>=0) return false ;
    if(j<0 && i>=0){
        for(int ind=0 ; ind<=i ; ind++){
            if(pattern[ind] != '*') return false ; 
        }
        return true ;
    }
    if(pattern[i] == text[j] || pattern[i] == '?') return recursion(i-1,j-1,pattern,text) ;
    if(pattern[i] == '*') 
        return recursion(i-1,j,pattern,text) | recursion(i,j-1,pattern,text) ;
    return false ; // if both characters doesn't match
}

bool memorization(int i,int j,string &pattern,string &text,vector<vector<int>> &dp){
    if(i<0 && j<0) return true ;
    if(i<0 && j>=0) return false ;
    if(j<0 && i>=0){
        for(int ind=0 ; ind<=i ; ind++){
            if(pattern[ind] != '*') return false ; 
        }
        return true ;
    }
    if(dp[i][j] != -1) return dp[i][j] ;
    if(pattern[i] == text[j] || pattern[i] == '?') return dp[i][j] = memorization(i-1,j-1,pattern,text,dp) ;
    if(pattern[i] == '*') 
        return dp[i][j] = memorization(i-1,j,pattern,text,dp) | memorization(i,j-1,pattern,text,dp) ;
    return dp[i][j] = false ; // if both characters doesn't match
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size() ;
    int m = text.size() ; 
    // RECURSION
    // return recursion(n-1,m-1,pattern,text) ;
    
    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(m,-1)) ;
    // return memorization(n-1,m-1,pattern,text,dp) ;
    /*
     // TABULATION
    // ASSUME AS 1 BASED INDEXING 
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,0)) ;
    // STEP 1 IN TABULATION --- WRITE BASECASES
    dp[0][0] = true ;
    for(int j=1 ; j<=m ; j++) dp[0][j] = false ;
    for(int i=1 ; i<=n ; i++){
        bool flag = true ;
        for(int ind=1 ; ind<=i ; ind++){
            if(pattern[ind-1] != '*'){
                flag = false ; break ;
            } 
        }
        // for every row 
        // you are assinging 0th colum value
        dp[i][0] = flag ;
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')                   dp[i][j] = dp[i-1][j-1] ;
            else if(pattern[i-1] == '*') 
                dp[i][j] = dp[i-1][j] | dp[i][j-1] ;
            else dp[i][j] = false ;
        }
    }
    return dp[n][m] ;
    */
    // SPACE OPTIMIZATION
    // ASSUME AS 1 BASED INDEXING 
    vector<bool> prev(m+1,false) , curr(m+1,false) ;
    prev[0] = true ;
    for(int j=1 ; j<=m ; j++) prev[j] = false ;
    
    for(int i=1 ; i<=n ; i++){
        // curr is the current rows column
        // and that curr 0th row has to be assigned everytime
        bool flag = true ;
        for(int ind=1 ; ind<=i ; ind++){
            if(pattern[ind-1] != '*'){
                flag = false ; break ;
            } 
        }
        curr[0] = flag ;
        for(int j=1 ; j<=m ; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')                   curr[j] = prev[j-1] ;
            else if(pattern[i-1] == '*') 
                curr[j] = prev[j] | curr[j-1] ;
            else curr[j] = false ;
        }
        prev = curr ;
    }
    return prev[m] ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        string pattern,text ;
        cin >> pattern >> text ;
        cout << wildcardMatching(pattern,text) << endl ;
    }
}
