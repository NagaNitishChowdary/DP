#include <bits/stdc++.h> 
using namespace std ;

int recursion(int ind,int maxWeight,vector<int> &weight,vector<int> &value){
    if(ind == 0){
        if(maxWeight >= weight[ind]) return value[ind] ;
        return 0 ;
    }
    int notPick = 0 + recursion(ind-1,maxWeight,weight,value);
    int pick = INT_MIN ;
    if(maxWeight >= weight[ind]) pick = value[ind] + recursion(ind-1,maxWeight-weight[ind],weight,value);
    return max(pick,notPick) ;
    
}

int memorization(int ind,int maxWeight,vector<int> &weight,vector<int> &value,vector<vector<int>> &dp){
    if(ind == 0){
        if(weight[ind] <= maxWeight) return value[ind] ;
        else return 0 ;
    }
    if(dp[ind][maxWeight] != -1) return dp[ind][maxWeight] ;
    int notPick = 0 + memorization(ind-1,maxWeight,weight,value,dp) ;
    int pick = INT_MIN ;
    if(weight[ind] <= maxWeight) pick = value[ind] + memorization(ind-1,maxWeight-weight[ind],weight,value,dp) ;
    return dp[ind][maxWeight] = max(pick,notPick) ;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    // RECURSION
    // return recursion(n-1,maxWeight,weight,value);
    
    // MEMORIZATION
    // vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // return memorization(n-1,maxWeight,weight,value,dp);

    // TABULATION
    /*
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0)) ;
    for(int i=weight[0] ; i<=maxWeight ; i++) dp[0][i] = value[0] ;
    for(int ind=1 ; ind<n ; ind++){
        for(int w=0 ; w<=maxWeight ; w++){
            int notPick = 0 + dp[ind-1][w] ;
            int pick = INT_MIN ;
            if(weight[ind] <= w) pick = value[ind] + dp[ind-1][w - weight[ind]] ;
            dp[ind][w] = max(pick , notPick) ;
        }
    }
    return dp[n-1][maxWeight] ;
    */

    // SPACE OPTIMIZATION 1
    /*
    vector<int> prev(maxWeight+1,0) , curr(maxWeight+1,0);
    for(int i=weight[0] ; i<=maxWeight ; i++) prev[i] = value[0] ;
    for(int ind=1 ; ind<n ; ind++){
        for(int w=0 ; w<=maxWeight ; w++){
            int notPick = 0 + prev[w] ;
            int pick = INT_MIN ;
            if(weight[ind] <= w) pick = value[ind] + prev[w-weight[ind]] ;
            curr[w] = max(pick , notPick) ;
        }
        prev = curr ;
    }
    return prev[maxWeight] ;
    */
    
    // SPACE OPTIMIZATION 2
    // INITIALLY PREV ROW IS FILLED THE NEXT ROW IS BASED ON PREV ROW
    // AS WE ARE OPTIMIZING TO ONLY ONE ARRAY SPACE OPTIMIZATION
    // WE ARE CALCULATING FROM MAXWEIGHT TO 0(for(int w=maxWeight ; w>=0 ; w--)) 
    vector<int> prev(maxWeight+1,0) ;
    for(int i=weight[0] ; i<=maxWeight ; i++) prev[i] = value[0] ;
    for(int ind=1 ; ind<n ; ind++){
        for(int w=maxWeight ; w>=0 ; w--){
            int notPick = 0 + prev[w] ;
            int pick = INT_MIN ;
            if(weight[ind] <= w) pick = value[ind] + prev[w-weight[ind]] ;
            prev[w] = max(pick , notPick) ;
        }
    }
    return prev[maxWeight] ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n;
        vector<int> weight(n),value(n);
        for(int i=0 ; i<n ; i++) cin >> weight[i] ;
        for(int i=0 ; i<n ; i++) cin >> value[i] ;
        int maxWeight; cin >> maxWeight ;
        cout <<  knapsack(weight,value,n,maxWeight) << endl ;
    }
}
