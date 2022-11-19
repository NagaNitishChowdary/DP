// WHEN 0 ALSO INCLUDED IN THE ELEMENTS

#include <bits/stdc++.h>
using namespace std;

int recursion1(int ind,vector<int> &num,int target){
    // if(target == 0) return 1;
    if(ind == 0){
        if(num[0] == 0 && target == 0) return 2 ;
        if(target == 0 || target == num[0]) return 1 ;
        return 0 ;
    }
    int notPick = recursion1(ind-1,num,target);
    int pick = 0;
    if(num[ind] <= target) pick = recursion1(ind-1,num,target-num[ind]);
    return pick + notPick ;
}

int memorization(int ind,vector<int> &num,int target,vector<vector<int>> &dp){
    // if(target == 0) return 1;
    if(ind == 0){
        if(target == 0 && num[0] == 0) return 2 ;
        if(target == 0 || target == num[0]) return 1 ; 
        return 0 ;
    }
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
    // return recursion1(num.size()-1,num,tar);
    
    // MEMORIZATION
     vector<vector<int>> dp(num.size(),vector<int>(tar+1,-1));
     return memorization(num.size()-1,num,tar,dp);

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
