// PROBLEM LINK --- https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;
template<typename T> 
istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> 
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> 
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; cout << endl ; return ostream; }

/*****************KNNC******************/

int recursion(int ind,int k,vector<int> &vt1){
    if(ind == 0) return 0 ; 
    int ans = INT_MAX ; 

    for(int i=1 ; i<=k ; i++){
        if(ind-i >= 0){
            ans = min(ans , recursion(ind-i,k,vt1) + abs(vt1[ind] - vt1[ind-i])) ;
        }
    }

    return ans ; 
}

int memoization(int ind,int k,vector<int> &vt1,vector<int> &dp){
    if(ind == 0) return 0 ; 
    int ans = INT_MAX ; 
    if(dp[ind] != -1) return dp[ind] ; 
    for(int i=1 ; i<=k ; i++){
        if(ind-i >= 0){
            ans = min(ans , memoization(ind-i,k,vt1,dp) + abs(vt1[ind] - vt1[ind-i])) ;
        }
    }

    return dp[ind] = ans ; 
}


void solve(){
    int n,k ; cin >> n >> k ;
    vector<int> vt1(n) ; cin >> vt1 ; 

    // RECURSION
    // cout << recursion(n-1,k,vt1) << endl ;

    // MEMOIZATION 
    // vector<int> dp(n,-1) ; 
    // cout << memoization(n-1,k,vt1,dp) << endl ; 

    // TABULATION 
    vector<int> dp(n,0) ; dp[0] = 0 ;
    for(int ind=1 ; ind<n ; ind++){
        int ans = INT_MAX ;  
        for(int i=1 ; i<=k ; i++){
            if(ind-i >= 0){
                ans = min(ans , dp[ind-i] + abs(vt1[ind] - vt1[ind-i])) ;
            }
        }

        dp[ind] = ans ; 
    }
    cout << dp[n-1] << endl ; 
}

int main() {
    solve();
    return 0;  
} 
