// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std ;

int recursion(int ind,int w,vector<int> &profit,vector<int> &weight){
    if(ind == 0){
        return profit[0]*(w/weight[0]) ;
        // else return 0 ;
    }
    int notPick = recursion(ind-1,w,profit,weight) ;
    int pick = INT_MIN ;
    if(w >= weight[ind]) pick = profit[ind] + recursion(ind,w-weight[ind],profit,weight) ;
    return max(pick,notPick) ;
}

int memorization(int ind,int w,vector<int> &profit,vector<int> &weight,vector<vector<int>> &dp){
    if(ind == 0) return profit[0]*(w/weight[0]) ;
    if(dp[ind][w] != -1) return dp[ind][w] ;
    int notPick = memorization(ind-1,w,profit,weight,dp) ;
    int pick = INT_MIN ;
    if(w >= weight[ind]) pick = profit[ind] + memorization(ind,w-weight[ind],profit,weight,dp) ;
    return dp[ind][w] = max(pick,notPick) ;
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    // RECURSION
    // return recursion(n-1,w,profit,weight) ;
    
    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(w+1,-1)) ;
    // return memorization(n-1,w,profit,weight,dp) ;
    
    // TABULATION
    /*
    vector<vector<int>> dp(n,vector<int>(w+1,0)) ;
    for(int i=0 ; i<=w ; i++){
        dp[0][i] = profit[0] * (i/weight[0]);
    }
    for(int ind=1 ; ind<n ; ind++){
        for(int weight1=0 ; weight1 <= w ; weight1++){
            int notPick = dp[ind-1][weight1] ;
            int pick = INT_MIN ;
            if(weight[ind] <= weight1) pick = profit[ind] + dp[ind][weight1-weight[ind]] ;
            dp[ind][weight1] = max(pick,notPick) ;
        }
    }
    return dp[n-1][w] ;
    */
    
    // SPACE OPTIMIZATION
    // USING 2 ARRAYS PREVIOUS AND CURRENT
    /*
    vector<int> curr(w+1,0) , prev(w+1,0) ;
    for(int i=0 ; i<=w ; i++){
        prev[i] = profit[0] * (i/weight[0]);
    }
    for(int ind=1 ; ind<n ; ind++){
        for(int weight1=0 ; weight1 <= w ; weight1++){
            int notPick = prev[weight1] ;
            int pick = INT_MIN ;
            if(weight[ind] <= weight1) pick = profit[ind] + curr[weight1-weight[ind]] ;
            curr[weight1] = max(pick,notPick) ;
        }
        prev = curr ;
    }
    return prev[w] ;
    */
    
    // SPACE OPTIMIZATION
    // USING ONLY 1 ARRAY
    vector<int> prev(w+1,0) ;
    for(int i=0 ; i<=w ; i++){
        prev[i] = profit[0] * (i/weight[0]);
    }
    for(int ind=1 ; ind<n ; ind++){
        for(int weight1=0 ; weight1 <= w ; weight1++){
            int notPick = prev[weight1] ;
            int pick = INT_MIN ;
            if(weight[ind] <= weight1) pick = profit[ind] + prev[weight1-weight[ind]] ;
            prev[weight1] = max(pick,notPick) ;
        }
    }
    return prev[w] ;
}

int main()
{
    int testCases; cin >> testCases;
    while(testCases--){
        int n,w ; cin >> n >> w ;
        vector<int> weight(n) , profit(w) ;
        for(int i=0 ; i<n ; i++) cin >> profit[i] ;
        for(int i=0 ; i<n ; i++) cin >> weight[i] ;
        cout << unboundedKnapsack(n,w,profit,weight) << endl ;
    }   
}
