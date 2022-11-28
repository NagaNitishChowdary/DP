// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std ;

string shortestSupersequence(string a, string b)
{
    int n = a.size() ;
    int m = b.size() ;
    //TABULATION
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            if(a[ind1-1] == b[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1] ;
            else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]) ;
        }
    }
    
    string ans = "" ;
    int i=n , j=m ;
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1] ;
            i-- ; j-- ; 
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans += a[i-1] ;
            i-- ;
        }
        else{
            ans += b[j-1] ;
            j-- ;
        }
    }
    while(i>0){
        ans += a[i-1] ;
        i-- ;
    }
    while(j>0){
        ans += b[j-1] ;
        j-- ;
    }
    reverse(ans.begin(),ans.end()) ;
    return ans ;
}

int main(){
    int testCases; cin >> testCases ;
    while(testCases--){
        string a,b ;
        cin >> a >> b ;
        string ans = shortestSupersequence(a,b) ;
        cout << ans << " " << ans.size() << "\n" ;
    } 
}
