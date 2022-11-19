// WHEN ELEMENTS ARE RANGE GREATER THAN 0
// IF 0 ALSO INCLUDED THEN COUNT WILL BE INCREASED

#include <bits/stdc++.h>
using namespace std;

int recursion1(int ind,int sum,vector<int> &num,int target){
    if(ind == num.size()){
        if(sum == target) return 1;
        else return 0;
    }
    int pick = recursion1(ind+1,sum+num[ind],num,target);
    int notpick = recursion1(ind+1,sum,num,target);
    return pick + notpick ;
}

int recursion2(int ind,vector<int> &num,int target){
    if(target == 0) return 1;
    if(ind == 0) return num[ind] == target ;
    int notPick = recursion2(ind-1,num,target);
    int pick = 0;
    if(num[ind] <= target) pick = recursion2(ind-1,num,target-num[ind]);
    return pick + notPick ;
}

int memorization(int ind,vector<int> &num,int target,vector<vector<int>> &dp){
    if(target == 0) return 1;
    if(ind == 0) return num[0] == target ;
    if(dp[ind][target] != -1) return dp[ind][target];
    int notPick = memorization(ind-1,num,target,dp);
    int pick = 0 ;
    if(num[ind] <= target) pick = memorization(ind-1,num,target-num[ind],dp);
    return dp[ind][target] = pick + notPick ;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // RECURSION
    // return recursion1(0,0,num,tar);
    // return recursion2(num.size()-1,num,tar);
    
    // MEMORIZATION
    // vector<vector<int>> dp(num.size(),vector<int>(tar+1,-1));
    // return memorization(num.size()-1,num,tar,dp);
    
    // TABULATION
    /*
    int n = num.size() ;
    vector<vector<int>> dp(n,vector<int> (tar+1,0));
    for(int i=0 ; i<n ; i++) dp[i][0] = 1 ;
    if(num[0] <= tar) dp[0][num[0]] = 1 ;
    for(int ind=1 ; ind<n ; ind++){
        for(int target=0 ; target<=tar ; target++){
            int notPick = dp[ind-1][target] ;
            int pick = 0 ;
            if(num[ind] <= target) pick = dp[ind-1][target-num[ind]] ;
            dp[ind][target] = pick + notPick ;
        }
    }
    return dp[n-1][tar] ;
    */
    
    // SPACE OPTIMIZAION
    int n = num.size();
    vector<int> prev(tar+1,0) , curr(tar+1,0) ;
    prev[0] = curr[0] = 1 ;
    if(num[0] <= tar) prev[num[0]] = 1 ;
    for(int ind=1 ; ind<n ; ind++){
        for(int target=0 ; target<=tar ; target++){
            int notPick = prev[target];
            int pick = 0 ;
            if(num[ind] <= target) pick = prev[target-num[ind]];
            curr[target] = pick + notPick ;
        }
        prev = curr; 
    }
    return prev[tar] ;
}

int main()
{
    int testCases; cin >> testCases;
    while(testCases--){
        int n,tar;
        cin >> n >> tar ;
        vector<int> num(n);
        for(int i=0 ; i<n ; i++) cin >> num[i] ;
        cout << findWays(num , tar) << "\n" ;
    }
}
