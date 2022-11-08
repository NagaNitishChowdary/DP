#include<bits/stdc++.h>
using namespace std;

int mod=(int)(1e9+7);

int recursion1(int i,int j,vector<vector<int>>&mat){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(mat[i][j]==-1) return 0;
    int up=recursion1(i-1,j,mat);
    int left=recursion1(i,j-1,mat);
    return up+left;
}

int memorization1(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(mat[i][j]==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=memorization1(i-1,j,mat,dp);
    int left=memorization1(i,j-1,mat,dp);
    return dp[i][j]=(up+left)%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    //int recursion=recursion1(n-1,m-1,mat);
    //return recursion;
    //vector<vector<int>>dp(n,vector<int>(m,-1));
    //int memorization=memorization1(n-1,m-1,mat,dp);
    //return memorization;
    //vector<vector<int>>dp(n,vector<int>(m,-1));
   
    // TABULATION
    /*
     int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) dp[i][j]=1;
            else if(mat[i][j]==-1) dp[i][j]=0;
            else{
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[n-1][m-1];
    
    */
    
    // SPACE OPTIMIZATION
    
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0) temp[j]=1;
            else if(mat[i][j]==-1) temp[j]=0;
            else{
                int up=0,left=0;
                if(i>0) up=prev[j];
                if(j>0) left=temp[j-1];
                temp[j]=(up+left)%mod;
            }
         }
        prev=temp;
    }
    return prev[m-1];
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat;
    for(int i=0;i<n;i++){
        vector<int>m1;
        for(int j=0;j<m;j++){
            int k; cin>>k;
            m1.emplace_back(k);
        }
        mat.emplace_back(m1);
    }
    cout<< mazeObstacles(n,m,mat) << "\n";
    return 0;
}
