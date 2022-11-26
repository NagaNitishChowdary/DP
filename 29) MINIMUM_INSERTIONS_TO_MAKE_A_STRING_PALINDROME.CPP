// PROBLEM LINK : https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// THE APPROACH IS (LENGTH OF THE STRING - LONGEST PALINDROMIC SUBSEQUENCE )

// MINIMUM INSERTIONS TO MAKE A STRING PALINDROME

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int i,int j,string s,string t){
    if(i<0 || j<0) return 0 ;
    if(s[i] == t[j]) return 1 + recursion(i-1,j-1,s,t) ;
    return max(recursion(i-1,j,s,t) , recursion(i,j-1,s,t)) ;
}

int memorization(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s[i] == t[j]) return 1 + memorization(i-1,j-1,s,t,dp) ;
    return max(memorization(i-1,j,s,t,dp) , memorization(i,j-1,s,t,dp)) ;
}

int minInsertion(string &str)
{
    // Write your code here.
    int n = str.size() ;
    string t = str ;
    reverse(t.begin(),t.end()) ;
    int m = t.size() ;
    
    // RECURSION
    // return n - recursion(n-1,n-1,str,t) ;
    
    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(m,-1)) ;
    // return n - memorization(n-1,n-1,str,t,dp) ;
    
    // TABULATION
    /*
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
    int ans = 0 ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(str[ind1-1] == t[ind2-1]){ dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1] ;
            ans = max(ans , dp[ind1][ind2]) ;
        }
            else dp[ind1][ind2] = max(dp[ind1-1][ind2] , dp[ind1][ind2-1]) ;
        }
    }
    return n - dp[n][m] ;
    */
    
    // SPACE OPTIMIZATION
    vector<int> prev(m+1,0) , curr(m+1,0) ;
    int ans = 0 ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(str[ind1-1] == t[ind2-1]){ curr[ind2] = 1 + prev[ind2-1] ;
            ans = max(ans , curr[ind2]) ;
        }
            else curr[ind2] = max(prev[ind2] , curr[ind2-1]) ;
        }
        prev = curr ;
    }
    return n - curr[m] ;
}

int main(){
    int testCases ; cin >> testCases ;
    while(testCases--){
        string str; cin >> str ;
        cout << minInsertion(str) << endl ;
    }
}
