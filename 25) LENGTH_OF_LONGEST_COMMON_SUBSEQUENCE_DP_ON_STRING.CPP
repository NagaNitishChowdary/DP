// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std ;

int recursion(int ind1,int ind2,string &s,string &t){
    if(ind1 < 0 || ind2 < 0) return 0 ;
    if(s[ind1] == t[ind2]) return 1 + recursion(ind1-1,ind2-1,s,t) ;
    return max(recursion(ind1-1,ind2,s,t) , recursion(ind1,ind2-1,s,t)) ;
}

int memorization(int ind1,int ind2,string &s,string &t,vector<vector<int>> &dp){
    if(ind1 < 0 || ind2 < 0) return 0 ;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2] ;
    if(s[ind1] == t[ind2]) return dp[ind1][ind2] = 1 + memorization(ind1-1,ind2-1,s,t,dp) ;
    return dp[ind1][ind2] = max(memorization(ind1-1,ind2,s,t,dp),memorization(ind1,ind2-1,s,t,dp)) ;
}

int recursion2(int ind1,int ind2,string &s,string &t){
    if(ind1 == 0 || ind2 == 0) return 0 ;
    if(s[ind1-1] == t[ind2-1]) return 1 + recursion2(ind1-1,ind2-1,s,t) ;
    return max(recursion2(ind1-1,ind2,s,t) , recursion2(ind1,ind2-1,s,t)) ;
}

int memorization2(int ind1,int ind2,string &s,string &t,vector<vector<int>> &dp){
    if(ind1 == 0 || ind2 == 0) return 0 ;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2] ;
    if(s[ind1-1] == t[ind2-1]) return dp[ind1][ind2] = 1 + memorization2(ind1-1,ind2-1,s,t,dp) ;
    return dp[ind1][ind2] = max(memorization2(ind1-1,ind2,s,t,dp),memorization2(ind1,ind2-1,s,t,dp)) ;
}

int lcs(string s, string t)
{
	//Write your code here
    // RECURSION
    // return recursion(s.size()-1,t.size()-1,s,t) ;
    
    // MEMORIZATION
     // vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1)) ;
     // return memorization(s.size()-1,t.size()-1,s,t,dp) ;
    
    // RECURSION2 -- SHIFTING OF INDEX FOR TABULATION
    // return recursion2(s.size(),t.size(),s,t) ;
    
    // MEMORIZATION2 --- SHIFTING OF INDEX FOR TABULATION
    // vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1)) ;
     // return memorization2(s.size(),t.size(),s,t,dp) ;
    
    // TABULATION
    /*
    int n = s.size() , m = t.size() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1)) ;
    for(int i=0 ; i<=n ; i++) dp[i][0] = 0 ;
    for(int j=0 ; j<=m ; j++) dp[0][j] = 0 ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(s[ind1-1] == t[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1] ;
     else dp[ind1][ind2] = max(dp[ind1-1][ind2] , dp[ind1][ind2-1]);
        }
    }
    return dp[n][m] ;
    */
    
    // SPACE OPTIMIZATION
    int n = s.size() , m = t.size() ;
    vector<int> prev(m+1,-1) , curr(m+1,0) ;
    for(int j=0 ; j<=m ; j++) prev[j] = 0 ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(s[ind1-1] == t[ind2-1]) curr[ind2] = 1 + prev[ind2-1] ;
     else curr[ind2] = max(prev[ind2] , curr[ind2-1]);
        }
        prev = curr ;
    }
    return curr[m] ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
    string s,t ;
    cin >> s >> t ;
    cout << lcs(s,t) << endl ;
    }
    return 0 ;
}
