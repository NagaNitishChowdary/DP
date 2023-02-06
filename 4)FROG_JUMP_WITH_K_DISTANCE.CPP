// PROBLEM LINK --- https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h> 
using namespace std;

int knnc(int n,vector<int>&heights,vector<int>&dp,int k){
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int mm=INT_MAX;
        for(int j=1;j<=k;j++){
            int knnc=INT_MAX;
            if(i-j>=0){
            knnc=dp[i-j]+abs(heights[i]-heights[i-j]);
            mm=min(mm,knnc);
            }
        }    
        dp[i]=mm;
    }
    return dp[n-1];
}

int frogJump(int n, vector<int> &heights,int k)
{
    // Write your code here.
    //vector<int>dp(n,-1);
    vector<int>dp(n,-1);
    return knnc(n,heights,dp,k);
}


int recursivefrogJump(int n,vector<int>&heights,int k)
{
    if(n==0) return 0;
    int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        int knnc=INT_MAX;
        if(n-i>=0) knnc=recursivefrogJump(n-i,heights,k)+abs(heights[n]-heights[n-i]);
        ans=min(knnc,ans);
    }
    return ans;
}


int memorizationfrogJump(int n,vector<int>&heights,vector<int>&dp,int k){
    if(n==0) return 0;
    int ans=INT_MAX;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=k;i++){
    int knnc=INT_MAX;
    if(n>=i) knnc=memorizationfrogJump(n-i,heights,dp,k)+abs(heights[n]-heights[n-i]);
    ans=min(knnc,ans);
    }
    return dp[n]=ans;
}


int main()
{
    int n; cin>>n;
    int k; cin>>k;
    vector<int>heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];
    cout<< frogJump(n,heights,k) <<"\n";
    cout<< recursivefrogJump(n-1,heights,k) << "\n";
    vector<int>dp(n,-1);
    cout<< memorizationfrogJump(n-1,heights,dp,k) << "\n";
    return 0;
}
