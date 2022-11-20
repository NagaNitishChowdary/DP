#include <bits/stdc++.h> 
using namespace std ;

int recursion(int ind,int target,vector<int> &num){
    if(ind == 0){
        if(target%num[ind] == 0) return target/num[ind] ;
        else return 1e9 ;
    }
    int notPick = 0 + recursion(ind-1,target,num) ;
    int pick = INT_MAX ;
    if(num[ind] <= target) pick = 1 + recursion(ind,target-num[ind],num);
    return min(pick,notPick) ;
}

int memorization(int ind,int target,vector<int> &num,vector<vector<int>> &dp){
    if(ind == 0){
        if(target%num[ind] == 0) return target/num[ind] ;
        else return 1e9 ;
    }
    if(dp[ind][target] != -1) return dp[ind][target] ;
    int notPick = 0 + memorization(ind-1,target,num,dp);
    int pick = INT_MAX ;
    if(num[ind] <= target) pick = 1 + memorization(ind,target-num[ind],num,dp);
    return dp[ind][target] = min(notPick,pick) ;
}

int minimumElements(vector<int> &num, int target)
{
    // Write your code here.
    // RECURSION
    // int n = num.size() ;
    // int ans = recursion(n-1,target,num);
    // if(ans >= 1e9) return -1;
    // return ans ;
    
    // MEMORIZATION
    // int n = num.size() ;
    // vector<vector<int>> dp(n,vector<int>(target+1,-1));
    // int ans = memorization(n-1,target,num,dp) ;
    // if(ans >= 1e9) return -1 ;
    // else return ans ;
    
    // TABULATION
    /*
    int n = num.size() ;
    vector<vector<int>> dp(n,vector<int> (target+1,0));
    for(int i=0 ; i<=target ; i++){
        if(i%num[0] == 0) dp[0][i] = i/num[0] ;
        else dp[0][i] = 1e9 ; 
    }
        for(int ind=1 ; ind<n ; ind++){
            for(int tar=0 ; tar<=target ; tar++){
               int notPick = 0 + dp[ind-1][tar];
               int pick = INT_MAX ;
               if(num[ind] <= tar) pick = 1 + dp[ind][tar-num[ind]];
               dp[ind][tar] = min(notPick,pick) ;
            }
        }
    int ans = dp[n-1][target] ;
    if(ans >= 1e9) return -1 ;
    else return ans ;
    */
    
    // SPACE OPTIMIZATION
    int n = num.size() ;
    vector<int> prev(target+1,0) , curr(target+1,0) ;
    for(int i=0 ; i<=target ; i++){
        if(i%num[0] == 0) prev[i] = i/num[0] ;
        else prev[i] = 1e9 ;
    }
    for(int ind=1 ; ind<n ; ind++){
        for(int tar=0 ; tar<=target ; tar++){
            int notPick = 0 + prev[tar] ;
            int pick = INT_MAX ;
            if(num[ind] <= tar) pick = 1 + curr[tar-num[ind]];
            curr[tar] = min(pick,notPick) ;
        }
        prev = curr ;
    }
    int ans = prev[target] ;
    if(ans >= 1e9) return -1 ;
    else return ans ;
      
}

int main()
{
    int testCases ; cin >> testCases;
    while(testCases--){
        int n,target ;
        cin >> n >> target ;
        vector<int> num(n) ;
        for(int i=0 ; i<n ; i++) cin >> num[i] ;
        cout << minimumElements(num,target) << "\n" ;
    }
}
