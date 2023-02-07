// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// LONGEST COMMON SUBSTRING

#include <bits/stdc++.h> 
using namespace std ;

int lcs(string &str1, string &str2){
	//	Write your code here.
    
    // TABULATION
    /*
    int n = str1.size() ;
    int m = str2.size() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
    for(int i=0 ; i<=n ; i++) dp[i][0] = 0 ;
    for(int j=0 ; j<=m ; j++) dp[0][j] = 0 ;
    int ans = 0 ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(str1[ind1-1] == str2[ind2-1]){ dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1] ;
            ans = max(ans,dp[ind1][ind2]) ; }
            else dp[ind1][ind2] = 0 ;
        }
    }
    return ans ;
    */
    // SPACE OPTIMIZAION  
    int n = str1.size() ;
    int m = str2.size() ;
    // vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
    vector<int>prev(m+1,0) , curr(m+1,0) ;
    // for(int i=0 ; i<=n ; i++) dp[i][0] = 0 ;
    // for(int j=0 ; j<=m ; j++) dp[0][j] = 0 ;
    int ans = 0 ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(str1[ind1-1] == str2[ind2-1]){ curr[ind2] = 1 + prev[ind2-1] ;
            ans = max(ans,curr[ind2]) ; }
            else curr[ind2] = 0 ;
        }
        prev = curr ;
    }
    return ans ;
}

int main(){
    int testCases ; cin >> testCases ;
    while(testCases--){
        string str1,str2 ;
        cin >> str1 >> str2 ;
        cout << lcs(str1,str2) << endl ;
    }
    return 0 ;
}
