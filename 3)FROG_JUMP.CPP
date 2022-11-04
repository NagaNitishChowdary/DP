#include <bits/stdc++.h> 
using namespace std;


int knnc(int n,vector<int>&heights){
    int prev=0;
    int prev1=0;
    for(int i=1;i<=n;i++){
        int left=prev+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1)
            right=prev1+abs(heights[i]-heights[i-2]);
        int curr=min(left,right);
        prev1=prev;
        prev=curr;
    }
    return prev;
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    //vector<int>dp(n,-1);
    return knnc(n-1,heights);
}

int recursivefrogJump(int n,vector<int>&heights)
{
    if(n==0) return 0;
    int one=recursivefrogJump(n-1,heights)+abs(heights[n]-heights[n-1]);
    int two=INT_MAX;
    if(n>1) two=recursivefrogJump(n-2,heights)+abs(heights[n]-heights[n-2]);
    return min(one,two);
}

int memorizationfrogJump(int n,vector<int>&heights,vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int one=memorizationfrogJump(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int two=INT_MAX;
    if(n>1) two=memorizationfrogJump(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    return dp[n]=min(one,two);
}

int main()
{
    int n; cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];
    cout<< frogJump(n,heights) <<"\n";
    cout<< recursivefrogJump(n-1,heights) << "\n";
    vector<int>dp(n,-1);
    cout<< memorizationfrogJump(n-1,heights,dp) << "\n";
    return 0;
}
