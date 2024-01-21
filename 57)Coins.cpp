// PROBLEM LINK --- https://atcoder.jp/contests/dp/tasks/dp_i

#include<bits/stdc++.h>
using namespace std;

template<typename T> 
istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> 
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> 
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; cout << endl ; return ostream; }
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007  

typedef long double ld ; 
typedef long long ll;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void solve(){
    ll n ; cin >> n ; 
    vector<ld> p(n) ; cin >> p ; 

    // STATE ---> dp[i][j] = probability of getting j number of heads
    // when i coins are tossed

    // TRANSISION --->
    //      If I get head on the ith toss
    //      dp[i-1][j-1]*p[i]
    //      If I get tail on the ith toss
    //      dp[i-1][j]*(1-p[i])

    // FINAL SUBPROBLEM ---> dp[n-1][j] where j=[n/2+1 ... n]

    vector<vector<ld>> dp(n,vector<ld> (n+1,0)) ; 

    // BASE CASE 
    dp[0][1] = p[0] ;  dp[0][0] = (1-p[0]) ; 

    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<=i+1 ; j++){
            if(j == 0){
                dp[i][0] = dp[i-1][0]*(1-p[i]) ; 
            } else {
                dp[i][j] = (dp[i-1][j-1]*p[i]) + (dp[i-1][j]*(1-p[i])) ;
            }
        } 
    }

    ld ans = 0.0 ; 
    for(int i=n/2+1 ; i<=n ; i++) ans += dp[n-1][i] ;
    cout << fixed << setprecision(10) << ans << endl ;  
}

int main() {
    fastio() ; 
    #ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr) ;
    #endif
    solve();
    return 0;  
} 
