// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

int recursion1(int i,int j,vector<vector<int>>&grid){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e+9;
    int up=recursion1(i-1,j,grid)+grid[i][j];
    int left=recursion1(i,j-1,grid)+grid[i][j];
    return min(up,left);
}

int memorization1(int i,int j, vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e+9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=grid[i][j]+memorization1(i-1,j,grid,dp);
    int left=grid[i][j]+memorization1(i,j-1,grid,dp);
    return dp[i][j]=min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    //int recursion=recursion1(grid.size()-1,grid[0].size()-1,grid);
    //return recursion;
    
    vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
    int memorization=memorization1(grid.size()-1,grid[0].size()-1,grid,dp);
    return memorization;
    
    // TABULATION
    /*
    vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(i==0 && j==0) dp[i][j]=grid[i][j];
           // else if(i<0 || j<0) dp[i][j]=1e+9;
            else{
                int up=grid[i][j],left=grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up=1e+9;
                if(j>0) left+=dp[i][j-1];
                else left=1e+9;
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[grid.size()-1][grid[0].size()-1];
    */
    /*
    // SPACE OPTIMIZATION
    
    vector<int>prev(grid[0].size(),0);
    for(int i=0;i<grid.size();i++){
        vector<int>curr(grid[0].size(),0);
        for(int j=0;j<grid[0].size();j++){
            if(i==0 && j==0) curr[j]=grid[i][j];
            else{
                int up=grid[i][j];
                int left=grid[i][j];
                if(i>0) up+=prev[j];
                else up=1e+9;
                if(j>0) left=curr[j-1];
                else left=1e+9;
                curr[j]=min(left,up);
            }
        }
        prev=curr;
    }
    return prev[grid[0].size()-1]+grid[grid.size()-1,grid[0].size()-1];
    */
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid;
    for(int i=0;i<m;i++){
        vector<int>m1;
        for(int j=0;j<n;j++){
            int k; cin>>k;
            m1.emplace_back(k);
        }
        grid.emplace_back(m1);
    }
    cout << minSumPath(grid);
}
