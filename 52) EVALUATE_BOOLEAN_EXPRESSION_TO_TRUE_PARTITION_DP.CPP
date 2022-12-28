// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
int mod = 1000000007 ;

ll recursion(int i,int j,int isTrue,string &exp){
    if(i > j) return 0 ;
    if(i == j){
        if(isTrue) return exp[i] == 'T' ;
        else return exp[i] == 'F' ;
    }
    ll ways = 0 ;
    for(int ind=i+1 ; ind<=j-1 ; ind+=2){
        // FIND THE NUMBER OF WAYS TO GET TRUE IN LEFT PARTITION
        ll lpt = recursion(i,ind-1,1,exp) ;
        // FIND THE NUMBER OF WAYS TO GET FALSE IN LEFT PARTITION
        ll lpf = recursion(i,ind-1,0,exp) ;
        // FIND THE NUMBER OF WAYS TO GET TRUE IN RIGHT PARTITION
        ll rpt = recursion(ind+1,j,1,exp) ;
        // FIND THE NUMBER OF WAYS TO GET FASLE IN RIGHT PARTITION
        ll rpf = recursion(ind+1,j,0,exp) ;
        // FOR VARIOUS OPERATORS VARIOUS WAYS ARE TO BE POSSIBLE
        if(exp[ind] == '&'){
            if(isTrue) ways += (lpt*rpt) ;
            else ways += (lpf*rpt + lpt*rpf + lpf*rpf) ;
        }
        else if(exp[ind] == '|'){
            if(isTrue) ways += (lpt*rpt + lpf*rpt + lpt*rpf) ;
            else ways += (lpf*rpf) ;
        }
        else if(exp[ind] == '^'){
            if(isTrue) ways += (lpt*rpf + lpf*rpt) ;
            else ways += (lpt*rpt + lpf*rpf) ;
        }
    }
    return ways ;
}

ll memoization(int i,int j,int isTrue,string &exp,vector<vector<vector<ll>>> &dp){
    if(i > j) return 0 ;
    if(i == j){
        if(isTrue) return exp[i] == 'T' ;
        else return exp[i] == 'F' ;
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue] ;
    ll ways = 0 ;
    for(int ind=i+1 ; ind<=j-1 ; ind+=2){
        // FIND THE NUMBER OF WAYS TO GET TRUE IN LEFT PARTITION
        ll lpt = memoization(i,ind-1,1,exp,dp) ;
        // FIND THE NUMBER OF WAYS TO GET FALSE IN LEFT PARTITION
        ll lpf = memoization(i,ind-1,0,exp,dp) ;
        // FIND THE NUMBER OF WAYS TO GET TRUE IN RIGHT PARTITION
        ll rpt = memoization(ind+1,j,1,exp,dp) ;
        // FIND THE NUMBER OF WAYS TO GET FASLE IN RIGHT PARTITION
        ll rpf = memoization(ind+1,j,0,exp,dp) ;
        // FOR VARIOUS OPERATORS VARIOUS WAYS ARE TO BE POSSIBLE
        if(exp[ind] == '&'){
            if(isTrue) ways = (ways + (lpt*rpt)%mod)%mod ;
            else ways = (ways + (lpf*rpt + lpt*rpf + lpf*rpf)%mod)%mod ;
        }
        else if(exp[ind] == '|'){
            if(isTrue) ways = (ways + (lpt*rpt + lpf*rpt + lpt*rpf)%mod)%mod ;
            else ways = (ways + (lpf*rpf)%mod)%mod ;
        }
        else if(exp[ind] == '^'){
            if(isTrue) ways = (ways + (lpt*rpf + lpf*rpt)%mod)%mod ;
            else ways = (ways + (lpt*rpt + lpf*rpf)%mod)%mod ;
        }
    }
    return dp[i][j][isTrue] = ways%mod ;
}

int evaluateExp(string & exp) {
    // Write your code here. 
    int n = exp.size() ;
    // RECURSION
    //return recursion(0,n-1,1,exp) ;
    // MEMOIZATION
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1))) ;
    return memoization(0,n-1,1,exp,dp) ;
}

int main()
{
    int testCases ; cin >> testCases ;
    while(testCases--){
        string exp ; cin >> exp ;
        cout << evaluateExp(exp) << endl ;
    }
    return 0 ;
}
