#include<bits/stdc++.h>
using namespace std ;

void lcs(string s, string t)
{
    // TABULATION    
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
    // return dp[n][m] ;
    int len = dp[n][m] ;
    string ans = "" ;
    for(int i=0 ; i<len ; i++) ans += '$' ;

    int index = len-1 ;
    int i=n , j=m ;
    while(i>0 && j>0){
        if(s[i-1] == t[j-1]){
            ans[index] = s[i-1] ;
            index-- ; i-- ; j-- ;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i-- ;
        else j-- ;
    }

    cout << ans << endl ;

}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
    string s,t ;
    cin >> s >> t ;
    lcs(s,t) ;
    }
    return 0 ;
}
