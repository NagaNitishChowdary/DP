#include<bits/stdc++.h>

#define LL long long int 
#define EB emplace_back
#define PB pop_back
#define F first
#define S second
#define MP make_pair
#define NEXT "\n"
#define LOOP(i,a,b) for(int i=a;i<b;i++) 

using namespace std;

/*****************KNNC******************/

int solve1(int n){
    if(n<=1) return n;
    else return solve1(n-1)+solve1(n-2);
}

int solve2(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    else return dp[n]=solve2(n-1,dp)+solve2(n-2,dp);
}

int solve3(int n){
    if(n<=1) return n;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n; cin>>n;
    cout<<solve1(n)<<NEXT;
    vector<int>dp(n+1,-1);
    //for(auto it:dp) cout<<it<<" "; 
    //cout<<NEXT;
    cout<<solve2(n,dp)<<NEXT;
    cout<<solve3(n)<<NEXT;
    return 0;  
}
