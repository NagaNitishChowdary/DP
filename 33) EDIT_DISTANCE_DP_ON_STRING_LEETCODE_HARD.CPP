// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// PROBLEM LINK --- https://leetcode.com/problems/edit-distance/description/

// THE INTUTION BEHIND THIS IS IF THE CHARACTERS ARE EQUAL THEN LEAVE THAT BOTH AND CHECKS BEFORE OF BOTH STRINGS
// ELSE 1 OPERATION IS REQUIRED IE INSERT OR DELETE OR REPLACE 

#include<bits/stdc++.h>
using namespace std ;

int recursion(int i,int j,string &word1,string &word2){
    if(i<0) return j+1 ;
    if(j<0) return i+1 ;
    if(word1[i] == word2[j]) return 0 + recursion(i-1,j-1,word1,word2);
    //             FOR INSERTING                 FOR DELETING                    FOR REPLACING
    return 1 + min(recursion(i-1,j,word1,word2),min(recursion(i,j-1,word1,word2),recursion(i-1,j-1,word1,word2))) ;
}

int memorization(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
    if(i<0) return j+1 ;
    if(j<0) return i+1 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(word1[i] == word2[j]) return  dp[i][j] = 0 + memorization(i-1,j-1,word1,word2,dp) ;    return dp[i][j] = 1 + min(memorization(i-1,j,word1,word2,dp),min(memorization(i,j-1,word1,word2,dp),memorization(i-1,j-1,word1,word2,dp))) ; 
}

int minDistance(string word1, string word2) {
    int n = word1.size() ;
    int m = word2.size() ;

    // RECURSION
    // return recursion(n-1,m-1,word1,word2) ;

    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(m,-1)) ;
    // return memorization(n-1,m-1,word1,word2,dp) ;

    // TABULATION
    /*
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
    for(int i=0 ; i<=n ; i++) dp[i][0] = i ;
    for(int j=0 ; j<=m ; j++) dp[0][j] = j ;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1] ;
            else dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) ;
        }
    }
    return dp[n][m] ;
    */
    // SPACE OPTIMIZATION
    vector<int> prev(m+1,0) , curr(m+1,0) ;
    for(int j=0 ; j<=m ; j++) prev[j] = j ;
    for(int i=1 ; i<=n ; i++){
        curr[0] = i ;
        for(int j=1 ; j<=m ; j++){
            if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1] ;
            else curr[j] = 1 + min(prev[j],min(curr[j-1],prev[j-1])) ;
        }
        prev = curr ;
    }
    return prev[m] ;
}


int main(){
    int testCases; cin >> testCases ;
    while(testCases--){
        string str1,str2 ;
        cin >> str1 >> str2 ;
        cout << minDistance(str1,str2) << endl ;
    }
}
