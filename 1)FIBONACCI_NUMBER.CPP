// PROBLEM LINK --- https://leetcode.com/problems/fibonacci-number/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156

#include<bits/stdc++.h>
#define LL long long int 
using namespace std;

int recursion(int n){
    if(n<=1) return n;
    else return recursion(n-1)+recursion(n-2);
}

int memorization(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    else return dp[n]=memorization(n-1,dp)+memorization(n-2,dp);
}

int tabulation(int n){
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
    cout<<recursion(n)<<NEXT;
    vector<int>dp(n+1,-1);
    //for(auto it:dp) cout<<it<<" "; 
    //cout<<NEXT;
    cout<<memorization(n,dp)<<NEXT;
    cout<<tabulation(n)<<NEXT;
    return 0;  
}
