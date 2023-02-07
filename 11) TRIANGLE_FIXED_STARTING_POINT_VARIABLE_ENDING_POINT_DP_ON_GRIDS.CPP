// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>>&triangle,int i,int j,int n){
    if(i==n-1) return triangle[n-1][j];
    int down=recursion(triangle,i+1,j,n)+triangle[i][j];
    int diagonal=recursion(triangle,i+1,j+1,n)+triangle[i][j];
    return min(down,diagonal);
}

int memorization(vector<vector<int>>&triangle,int i,int j,int n,vector<vector<int>>&dp){
    if(i==n-1) return triangle[n-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down=triangle[i][j]+memorization(triangle,i+1,j,n,dp);
    int diagonal=triangle[i][j]+memorization(triangle,i+1,j+1,n,dp);
    return dp[i][j]=min(down,diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    //int recursion1=recursion(triangle,0,0,n);
    //return recursion1;
    
    //vector<vector<int>>dp(n,vector<int>(n,-1));
    //int memorization1=memorization(triangle,0,0,n,dp);
    //return memorization1;
    
    // TABULATION
    /*
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        dp[n-1][i]=triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=triangle[i][j]+dp[i+1][j];
            int diagonal=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(down,diagonal);
        }
    }
    return dp[0][0];
    */
    
    // SPACE OPTIMIZATION
    vector<int>prev(n,0);
    for(int i=0;i<n;i++){
        prev[i]=triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        vector<int>curr(n,0);
        for(int j=i;j>=0;j--){
            int down=triangle[i][j]+prev[j];
            int diagonal=triangle[i][j]+prev[j+1];
            curr[j]=min(down,diagonal);
        }
        prev=curr;
    }
    return prev[0];
}

int main()
{
    int n; cin>>n;
    vector<vector<int>>triangle ; //={{2},{3,4},{6,5,7},{4,1,8,3}};
    for(int i=1;i<=n;i++){
        vector<int>knnc;
        for(int j=0;j<i;j++){
            int k; cin>>k;
            knnc.emplace_back(k);
        }
        triangle.emplace_back(knnc);
    }
    
    //triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumPathSum(triangle,n) << endl ;
    return 0;
}
