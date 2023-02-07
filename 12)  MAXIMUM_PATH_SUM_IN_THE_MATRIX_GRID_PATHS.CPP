// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int i,int j,vector<vector<int>>&matrix){
    if(j<0 || j>=matrix[0].size()) return -1e8 ;
    if(i==0) return matrix[0][j];
    int up = matrix[i][j] + recursion(i-1,j,matrix);
    int ld = matrix[i][j] + recursion(i-1,j-1,matrix);
    int rd = matrix[i][j] + recursion(i-1,j+1,matrix);
    return max(up,max(ld,rd));
}

int memorization(int i , int j , vector<vector<int>>&matrix,vector<vector<int>>&dp){
    if(j < 0 || j >= matrix[0].size()) return -1e8 ;
    if(i == 0) return matrix[0][j];
    if(dp[i][j] != -1) return dp[i][j] ;
    int up = matrix[i][j] + memorization(i-1 , j , matrix,dp);
    int ld = matrix[i][j] + memorization(i-1 , j-1 , matrix,dp);
    int rd = matrix[i][j] + memorization(i-1 , j+1 , matrix,dp);
    return dp[i][j] = max(up, max(ld,rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    // RECURSION 
    /*
    int maxi = -1e8 ;
    for(int k=0 ; k<m ; k++){
        maxi = max(maxi , recursion(n-1,k,matrix));
    }
    return maxi ;
    */
    
    // MEMORIZATION
    /*
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int maxi = -1e8 ;
    for(int k=0 ; k<m ; k++){
        maxi = max(maxi , memorization(n-1,k,matrix,dp));
    }
    return maxi ;
    */
    
    /*
    // TABULATION
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=0 ; j<m ; j++) dp[0][j] = matrix[0][j] ;
    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int up = matrix[i][j] + dp[i-1][j] ;
            int ld = -1e8 ;
            if(j > 0) ld = matrix[i][j] + dp[i-1][j-1] ;
            int rd = -1e8 ;
            if(j < m-1) rd = matrix[i][j] + dp[i-1][j+1] ;
            dp[i][j] = max(up , max(ld,rd));
        }
    }
    int maxi = -1e8 ;
    for(int h=0 ; h<m ; h++) maxi = max(maxi , dp[n-1][h]);
    return maxi ;
    
    */
    
    // SPACE OPTIMIZATION
    vector<int>prev(m,0) , curr(m,0) ;
    for(int i=0 ; i<m ; i++) prev[i] = matrix[0][i] ;
    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int up = matrix[i][j] + prev[j] ;
            int ld = -1e8 ;
            if(j > 0) ld = matrix[i][j] + prev[j-1] ;
            int rd = -1e8 ;
            if(j < m-1) rd = matrix[i][j] + prev[j+1] ;
            curr[j] = max(up , max(ld,rd));
        }
        prev = curr ;
    }
    int maxi = -1e8 ;
    for(int h=0 ; h<m ; h++) maxi = max(maxi,prev[h]);
    return maxi ;
}

int main(){
    int testCases; cin >> testCases ;
    while(testCases--){
        int n,m ;
        cin >> n >> m ;
        vector<vector<int>> matrix ;
        for(int i=0 ; i<n ; i++){
            vector<int> knnc(m,0);
            for(int j=0 ; j<m ; j++) cin >> knnc[j] ;
            matrix.emplace_back(knnc) ;
        }
        cout << getMaxPathSum(matrix) << endl ;
    }
}
