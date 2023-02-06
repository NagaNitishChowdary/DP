// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;
vector<int>dp(100000);
int countDistinctWays(int nStairs) {
    //long long int a=1,b=1;
    long long mod=1000000007;
    dp[0]=1;
    dp[1]=1;
    if(nStairs<=1) return 1;
    for(long long int i=2;i<=nStairs;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    return dp[nStairs];
}

int main()
{
    int nStairs; cin>>nStairs;
    cout<< countDistinctWays(nStairs) <<"\n";
    return 0;
}
