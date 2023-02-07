// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include<bits/stdc++.h>
using namespace std ;

int recursion(int ind,int value,int *denominations){
    if(ind == 0) return value%denominations[ind] == 0 ;
    int notPick = recursion(ind-1,value,denominations) ;
    int pick = 0 ;
    if(denominations[ind] <= value) pick = recursion(ind,value-denominations[ind],denominations) ;
    return pick + notPick ;
}

int memorization(int ind,int value,int *denominations,vector<vector<int>> &dp){
    if(ind == 0) return value%denominations[ind] == 0 ;
    if(dp[ind][value] != -1) return dp[ind][value] ;
    int notPick = memorization(ind-1,value,denominations,dp);
    int pick = 0 ;
    if(denominations[ind] <= value) pick = memorization(ind,value-denominations[ind],denominations,dp) ;
    return dp[ind][value] = pick + notPick ;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    // RECURSION
    // return recursion(n-1,value,denominations) ;
    
    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(value+1,-1)) ;
    // return memorization(n-1,value,denominations,dp) ;

    // TABULATION
    /*
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    for(int i=0 ; i<=value ; i++)
        dp[0][i] = (i%denominations[0] == 0) ;
    for(int ind=1 ; ind<n ; ind++){
        for(int target=0 ; target<=value ; target++){
            long notPick = dp[ind-1][target] ;
            long pick = 0 ;
            if(denominations[ind] <= target)  pick = dp[ind][target-denominations[ind]] ;
            dp[ind][target] = notPick + pick ;
        }
    }
    return dp[n-1][value] ;
    */
    
    // SPACE OPTIMIZATION
    vector<long> curr(value+1,0) , prev(value+1,0) ;
    for(int i=0 ; i<=value ; i++)
        prev[i] = (i%denominations[0] == 0) ;
    for(int ind=1 ; ind<n ; ind++){
        for(int target=0 ; target<=value ; target++){
            long notPick = prev[target] ;
            long pick = 0 ;
            if(denominations[ind] <= target)  pick = curr[target-denominations[ind]] ;
            curr[target] = notPick + pick ;
        }
        prev = curr ;
    }
    return prev[value] ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n ;
        int denominations[n];
        for(int i=0;i<n;i++) cin >> denominations[i] ;
        int value ; cin >> value ;
        cout << countWaysToMakeChange(denominations,n,value) << endl ;
    }
}
